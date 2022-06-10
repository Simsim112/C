#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char element;

typedef struct node {
	element data;
	struct node* link;
}Node;

typedef struct {
	Node* rear;
	Node* front;
}Qlink;

Qlink* CreateQ();
bool isEmpty(Qlink* aql);
void enQueue(Qlink* aql, element adata);
void printQ(Qlink* aql);
element deQueue(Qlink* aql);

int main()
{
	Qlink* q = CreateQ();
	enQueue(q, 'A');
	enQueue(q, 'B');
	enQueue(q, 'C');
	enQueue(q, 'D');
	printf("%c", deQueue(q));
	printf("%c", deQueue(q));
	printf("%c", deQueue(q));
	printf("%c", deQueue(q));
	printf("%p %p", q->front, q->rear);
	//printQ(q);
	return 0;
}


Qlink* CreateQ()
{
	Qlink* ql = (Qlink*)malloc(sizeof(Qlink));
	if (ql == NULL) exit(1);
	ql->front = NULL;
	ql->rear = NULL;
	return ql;
}

bool isEmpty(Qlink* aql) {
	if (aql->front == NULL) {
		printf("Queue is Empty!!");
		return true;
	}
	else return false;
}

void enQueue(Qlink* aql, element adata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) exit(1);
	newNode->data = adata;
	newNode->link = NULL;
	if (isEmpty(aql))
	{
		aql->front = newNode;
		aql->rear = newNode;
	}
	else {
		aql->rear->link = newNode;
		aql->rear = newNode;
	}
}

void printQ(Qlink* aql)
{
	Node* curr = aql->front;

	while (curr) {
		printf("%c ", curr->data);
		curr = curr->link;
	}

}
element deQueue(Qlink* aql)
{
	Node* del = aql->front;
	element data;
	if (isEmpty(aql)) return 0;
	else {
		data = aql->front->data;
		aql->front = aql->front->link;
		if (aql->front == NULL) {
			aql->rear = NULL;
		}
		free(del);
		return data;
	}
}
	