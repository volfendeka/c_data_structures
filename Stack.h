#include<stdlib.h>
#include<stdio.h>

typedef struct SNode *snode;
typedef struct Stack *stack;

struct SNode{
        int value;
        struct SNode *next;
};

struct Stack{
	int length;
	struct SNode *head;
	struct SNode *tail;
};

stack createStack(){
	stack s;
	s = (stack)malloc(sizeof(struct Stack));
	s->length = 0;
	s->head = NULL;
	s->tail = NULL;
	return s;
}

snode createSNode(){
	snode item;
	item = (snode)malloc(sizeof(struct SNode));
	item->next = NULL;
	return item;
}

stack addSNode(stack s, int value){
	snode item;

	//initialize new item in the list
	item = createSNode();
	item->value = value;

	if(s->head == NULL){
		s->head = item;
	}else{
		if(s->tail == NULL){
                	s->tail = s->head;
                }
		item->next = s->head;
		s->head = item;
	}
	s->length++;
	return s;
}
snode pollStack(stack s){
	snode head;
	head = s->head;
	s->head = head->next;
	s->length--;
	return head;
}
