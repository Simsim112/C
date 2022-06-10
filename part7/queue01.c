//�����ڷᱸ���� ť 
#include <stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define SIZE 10

typedef char element;

typedef struct {
	element que[SIZE];		//ť�迭
	int front, rear;		//��ġ���, front(�ⱸ), rear(�Ա�)
}Queue;

Queue* createQ();
bool isEmpty(Queue* apq);
bool isFull(Queue* apq);
void enQueue(Queue* apq, element adata);
element deQueue(Queue* apq);
element peek(Queue* apq);
void printQ(Queue* apq);

int main()
{
	Queue* Q = createQ();
	enQueue(Q, 'A');
	enQueue(Q, 'B');
	//printf("%c", deQueue(Q));
	//printf("%c", peek(Q));
	printQ(Q);
	return 0;
}

Queue* createQ()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL) exit(1);
	q->front = -1;
	q->rear = -1;
	return q;
}

bool isEmpty(Queue* apq)
{
	if (apq->front == apq->rear) {
		printf("Queue is empty!!");
		return true;
	}
	else return false;
}

bool isFull(Queue* apq)
{
	if (apq->rear >= SIZE -1) {
		printf("Queue is full!!");
		return true;
	}
	else return false;
}

void enQueue(Queue* apq, element adata)
{
	if (isFull(apq)) return;
	apq->que[++(apq->rear)] = adata;
}

element deQueue(Queue* apq)
{
	if (isEmpty(apq)) return;
	return apq->que[++(apq->front)];
}

element peek(Queue* apq)
{
	if (isEmpty(apq)) return;
	return apq->que[apq->rear];
}

void printQ(Queue* apq)
{
	if (isEmpty(apq)) return;
	else 
	{
		for (int i = apq->front + 1; i <= apq->rear; i++) 
		{
			printf("%c", deQueue(apq));
		}
	}
}