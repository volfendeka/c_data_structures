#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Dict.h"

void test_queue();
void test_linked_list();
void test_stack();
void ask_for_test();
void print_separator();
void test_dict();

int main()
{
	ask_for_test();

	return 0;
}

void ask_for_test(){
	int test;
        printf("Test data structures:");
	print_separator();
	printf("\"1\" for LinkedList \n");
	printf("\"2\" for Queue \n");
	printf("\"3\" for Stack \n");
	printf("\"4\" for Dict \n");
	scanf("%d", &test);
        switch(test){
                case 1:
                        test_linked_list();
                        break;
		case 2:
			test_queue();
			break;
		case 3:
			test_stack();
			break;
		case 4:
			test_dict();
			break;
                default:
                        printf("Select existing option!");
         		ask_for_test();
        }
}

void test_dict(){
    Dict d;
    char buf[512];
    int i;

    d = DictCreate();

    DictInsert(d, "foo", "hello world");
    puts(DictSearch(d, "foo"));
    DictInsert(d, "foo", "hello world2");
    puts(DictSearch(d, "foo"));
    DictDelete(d, "foo");
    puts(DictSearch(d, "foo"));
    DictDelete(d, "foo");
    assert(DictSearch(d, "foo") == 0);
    DictDelete(d, "foo");

    for(i = 0; i < 10000; i++) {
        sprintf(buf, "%d", i);
        DictInsert(d, buf, buf);
    }

    printf("%d", d->size);
    DictDestroy(d);
}

void test_linked_list(){
 	int counter, items;
        list linkedList;

        printf("LinkedList elements amount: \n");
        scanf("%d", &items);
        counter = 0;
        linkedList = createList();
        while(counter < items){
                counter++;
                linkedList = addNode(linkedList, counter);
        }
        linkedList = iterate(linkedList);
	printf("Length: %d \n", linkedList->length);
	free(linkedList);
}

void test_queue(){
	int counter, items;
	queue q;
	qnode node;
	
	printf("Queue elements amount: \n");
        scanf("%d", &items);

	q = createQueue();
	counter = 0;
	while(counter < items){
		counter++;
		addQNode(q, counter);
	}
	printf("Queue Length: %d \n", q->length);
	while(q->length > 0){
		node = pollQueue(q);
		printf("Poll node: %d \n", node->value);
	}
	free(q);
}

void test_stack(){
	int counter, items;
        stack s;
        snode node;
        
        printf("Stack elements amount: \n");

        scanf("%d", &items);

        s = createStack();
        counter = 0;
        while(counter < items){
                counter++;
                addSNode(s, counter);
        }
        printf("Stack Length: %d \n", s->length);
        while(s->length > 0){
                node = pollStack(s);
                printf("Poll node: %d \n", node->value);
        }
        free(s);
}

void print_separator(){
	int i;
	printf("\n");
	for(i=0; i<=50; i++){
		printf("-");
	}
	printf("\n");
}
