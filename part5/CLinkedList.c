#include <stdio.h>
#include <stdlib.h>

//�������Ḯ��Ʈ������ tail�ϳ��� ����ϰ� ��������带 ����Ŵ
typedef struct _node {
	int data;
	struct _node* next;
}CNode;

CNode* insertFirstNode(CNode*, int);
CNode* insertLastNode(CNode*, int);
void printNode(CNode*);
void allDelNode(CNode*);
//CNode* searchNode(CNode*, int);
//void removeNode(CNode*, int);

int main()
{
	CNode* tail = NULL;
	tail = insertFirstNode(tail, 10);
	tail = insertFirstNode(tail, 20);
	tail = insertLastNode(tail, 30);
	printNode(tail);
	allDelNode(tail);
	return 0;
}

CNode* insertFirstNode(CNode* t, int d)
{
	CNode* newNode = (CNode*)malloc(sizeof(CNode));
	if (newNode == NULL) return;

	newNode->data = d;
	newNode->next = NULL;
	
	if (t == NULL)
	{
		t = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = t->next;
		t->next = newNode;
	}
	return t;
}

CNode* insertLastNode(CNode* t, int d)
{
	CNode* newNode = (CNode*)malloc(sizeof(CNode));
	if (newNode == NULL) return;

	newNode->data = d;
	newNode->next = NULL;

	newNode->next = t->next;
	t->next = newNode;
	t = newNode;

	return t;
}

void printNode(CNode* t) {

	CNode* curr = t->next;

	do{
		printf("%d ", curr->data);
		curr = curr->next;
	} while (curr != t->next);
}

//��������� �� �𸣰��� 
void allDelNode(CNode* t) {
	CNode* curr = t->next;
	CNode* temp;
	do {
		curr = curr->next;
		if (curr == t) {
			temp = curr;
			curr = curr->next;
			temp->next = NULL;
			break;
		}
	} while (curr != t->next);

	printf("\n");
	while (curr != NULL) {
		printf("%d ������ ���\n", curr->data);
		temp = curr;
		curr = curr->next;
		free(temp);
	};
}