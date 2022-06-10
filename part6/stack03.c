// ���Ḯ��Ʈ�� ������ ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;		//���� �ڷ���

typedef struct node {		//����Ʈ ����ü
	int data;
	struct node* link;
}Node;

typedef struct {			//��� ����ü 
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
		printf("������ ����ֽ��ϴ�.\n");
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