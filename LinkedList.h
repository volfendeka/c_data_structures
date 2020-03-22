#include<stdlib.h>
#include<stdio.h>

typedef struct Node *node;
typedef struct List *list;

struct Node{
        int value;
        struct Node *next;
};

struct List{
	int length;
	struct Node *head;
	struct Node *tail;
};

list createList(){
	list l;
	l = (list)malloc(sizeof(struct List));
	l->length = 0;
	l->head = NULL;
	l->tail = NULL;
	return l;
}

node createNode(){
	node item;
	item = (node)malloc(sizeof(struct Node));
	item->next = NULL;
	return item;
}

list addNode(list linkedList, int value){
	node previous, item, head;
	head = linkedList->head;

	//initialize new item in the list
	item = createNode();
	item->value = value;

	if(head == NULL){
		head = item;
		linkedList->head = head;
	}else{
		if(linkedList->tail != NULL){
			linkedList->tail->next = item;
			linkedList->tail = item;
		}else{
			linkedList->tail = item;
			linkedList->head->next = item;
		}
	}
	linkedList->length++;
	return linkedList;
}

list iterate(list linkedList){
	node previous;
	previous = linkedList->head;
	while(previous != NULL){
		//todo:: proces with callback function
		printf("Value: %d \n", previous->value);
		previous = previous->next;
	}
	return linkedList;
}
