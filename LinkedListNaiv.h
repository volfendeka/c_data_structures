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
	struct Node head;
	struct Node tail;
};

node createNode(){
	node item;
	item = (node)malloc(sizeof(struct Node));
	item->next = NULL;
	return item;
}

node addNode(node head, int value){
	node previous, item;

	//initialize new item in the list
	item = createNode();
	item->value = value;

	if(head == NULL){
		head = item;
	}else{
		previous = head;
		while(previous->next != NULL){
			previous = previous->next;
		}
		previous->next = item;
	}
	return head;
}

node iterate(node head){
	node previous;
	previous = head;
	while(previous != NULL){
		//todo:: proces with callback function
		printf("Value: %d \n", previous->value);
		previous = previous->next;
	}
	return head;
}
