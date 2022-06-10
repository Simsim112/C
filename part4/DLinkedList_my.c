#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
}Node;

void pre_insertNode(Node* h, int d)		//�������Գ�� 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	newNode->data = d;
	newNode->next = h->next;
	h->next = newNode;
}

void rear_insertNode(Node* h, int d)	//�������Գ��
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	Node* curr = (Node*)malloc(sizeof(Node));
	newNode->data = d;

	/*curr = h;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	newNode->next = curr->next;
	curr->next = newNode;*/

	newNode->next = NULL;
	curr = h->next;
	if (curr == NULL)
	{
		h->next = newNode;
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

void printNode(Node* h)
{
	Node* curr = (Node*)malloc(sizeof(Node));
	curr = h;
	while (curr->next != NULL)
	{
		curr = curr->next;
		printf("%d\n", curr->data);
	}
}

void printNode2(Node* h)
{
	Node* curr = (Node*)malloc(sizeof(Node));
	curr = h->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

void freeNode(Node* h)
{
	Node* curr;
	curr = h->next;
	while (curr != NULL)
	{
		h->next = curr->next;
		free(curr);
		curr = h->next;
	}
	free(h);

	//while (h->next == NULL) {
	//	curr = h->next;
	//	h->next = h->next->next;
	//	free(curr);
	//	curr = NULL;
	//}
	//free(h)
}

Node* searchNode(Node* h, int data)
{
	Node* curr;
	curr = h->next;
	while (curr != NULL)
	{
		if (data == curr->data) {
			printf("%d ã��\n", curr->data);
			return curr;
		}
		curr = curr->next;
	}
	printf("ã�°��� �����ϴ�.\n");
	return NULL;
}

void deleteNode(Node* h, Node* target)
{
	//Node* curr = h;
	//Node* prev;
	//while (curr->next != NULL)
	//{
	//	prev = curr;
	//	curr = curr->next;
	//	if (curr == target)
	//	{
	//		prev->next = curr->next;
	//		free(curr);
	//		break;
	//	}
	//}
	//prev �Ⱦ��� �׳� �ϴ°� ���� �ȸ������
	Node* curr = h;
	while (curr->next != NULL)
	{
		if (curr->next == target)
		{
			curr->next = curr->next->next;
			curr = curr->next;
			free(curr);
			break;
		}
		curr = curr->next;
	}
}

void AddNode(Node* h, int data, int input)
{
	Node* curr = h;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = input;
	newNode->next = NULL;

	while (curr->next != NULL)
	{
		curr = curr->next;
		if (curr->data == data)
		{
			newNode->next = curr->next;
			curr->next = newNode;
			break;
		}
	}
}

int main()
{
	Node* Head = (Node*)malloc(sizeof(Node));
	Node* target;
	if (Head != NULL) Head->next = NULL;

	pre_insertNode(Head, 10);
	pre_insertNode(Head, 20);
	pre_insertNode(Head, 30);
	rear_insertNode(Head, 100);
	printNode2(Head);
	target = searchNode(Head, 100);
	deleteNode(Head, target);
	//AddNode(Head, 100, 900);
	//AddNode(Head, 30, 1900);
	printNode2(Head);
	//freeNode(Head);
	//rear_insertNode(Head, 100);
	//pre_insertNode(Head, 30);
	//printNode2(Head);
	return 0;
}

