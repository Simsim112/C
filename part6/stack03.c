// 연결리스트로 구현된 스택
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;		//스택 자료형

typedef struct node {		//리스트 구조체
	int data;
	struct node* link;
}Node;

typedef struct {			//헤드 구조체 
	Node* head;
}HStack;

HStack* createHead();
bool isEmpty(HStack*);
void push(HStack*, element);
element pop(HStack*);
element peek(HStack*);
int main()
{
	HStack* H = createHead();
	push(H, 10);
	push(H, 20);

	printf("%d", pop(H));
	printf("%d", pop(H));
	return 0;
}

HStack* createHead()
{
	HStack* h = (HStack*)malloc(sizeof(HStack));
	if (h == NULL) exit(1);
	h->head = NULL;
	return h;
}

bool isEmpty(HStack* ahead)
{
	if (ahead->head == NULL) return true;
	else return false;
}

void push(HStack* ahead, element value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->link = ahead->head;
	ahead->head = newNode;
}

element pop(HStack* ahead)
{
	Node* curr = (Node*)malloc(sizeof(Node));
	element d;

	if (isEmpty(ahead))
	{
		printf("스택이 비어있습니다.\n");
		return 0;
	}
	else {
		d = ahead->head->data;
		curr = ahead->head;
		ahead->head = ahead->head->link;
		free(curr);
		return d;
	}
}