#include<stdlib.h>
#include<stdio.h>

typedef struct QNode *qnode;
typedef struct Queue *queue;

struct QNode{
        int value;
        struct QNode *next;
};

struct Queue{
	int length;
	struct QNode *head;
	struct QNode *tail;
};

queue createQueue(){
	queue q;
	q = (queue)malloc(sizeof(struct Queue));
	q->length = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

qnode createQNode(){
	qnode item;
	item = (qnode)malloc(sizeof(struct QNode));
	item->next = NULL;
	return item;
}

queue addQNode(queue q, int value){
	qnode item;

	//initialize new item in the list
	item = createQNode();
	item->value = value;

	if(q->head == NULL){
		q->head = item;
	}else{
		if(q->tail != NULL){
			q->tail->next = item;
			q->tail = item;
		}else{
			q->tail = item;
			q->head->next = item;
		}
	}
	q->length++;
	return q;
}
qnode pollQueue(queue q){
	qnode head;
	head = q->head;
	q->head = head->next;
	q->length--;
	return head;
}
