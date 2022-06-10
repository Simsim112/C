#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
	int data;
	struct dnode* next;
	struct dnode* prev;
}Dnode;

void insertNode(Dnode*, int, Dnode*, char); //�Ǹ����� �ɼ� n p �� �� ����
Dnode* searchNode(Dnode*, int);
void printNode(Dnode*);
void allDelNode(Dnode*);
void removeNode(Dnode*, Dnode*);
int main()
{
	Dnode* head = (Dnode*)malloc(sizeof(Dnode));
	if (head == NULL) exit(1);
	head->next = NULL;
	head->prev = NULL;
	Dnode* pos = NULL;		//���س��, �˻������ �ּҸ� ���� 

	insertNode(head, 10, pos, 'n');
	insertNode(head, 50, pos, 'n');
	insertNode(head, 70, pos, 'n');
	pos = searchNode(head, 10);

	removeNode(head, pos);
	printNode(head);

	pos = searchNode(head, 70);
	insertNode(head, 60, pos, 'n');
	printNode(head);
	//allDelNode(head);
	return 0;
}

void insertNode(Dnode* h, int d, Dnode* p , char opt)
{
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));
	if (newNode == NULL) return;
	newNode->data = d;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (p == -1);
	else
	{
		if (p == NULL)					//ù��° ���� ����
		{
			newNode->next = h->next;
			if (h->next != NULL)		//��������Ʈ�� ���� ��� 
			{
				newNode->next->prev = newNode;
			}
			h->next = newNode;		    //��������Ʈ�� �ƹ��͵� ������� 
		}
		else {							//���ϴ� ��ġ���ٰ� ���������� 
			Dnode* curr = h->next;
			while (curr != p)
			{
				curr = curr->next;
			}

			if (opt == 'p') //���� ���� 
			{
				newNode->prev = curr->prev;
				newNode->next = curr;
				if (newNode->prev != NULL)
					newNode->prev->next = newNode;
				else
					h->next = newNode;				//�������� �ճ�尡 head�� ��� 
				curr->prev = newNode;
			}
			else if (opt == 'n') //���� ���� 
			{
				newNode->next = curr->next;
				newNode->prev = curr;
				if (curr->next != NULL)
					curr->next->prev = newNode;  //��������尡 �ƴѰ�� 
				curr->next = newNode;
			}
		}
	}
}

void printNode(Dnode* h) 
{
	Dnode* curr = h->next;
	if (h->next == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	}
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
}

Dnode* searchNode(Dnode* h, int d)
{
	Dnode* curr = h->next;

	while (curr != NULL)
	{
		if (curr->data == d)
			return curr;
		curr = curr->next;
	}
	printf("ã�� ���� �����ϴ�.\n");
	return -1;
}

void allDelNode(Dnode* h) 
{
	Dnode* curr = h->next;

	while (curr != NULL)
	{
		h->next = curr->next;
		//printf("%d�� �����մϴ�.\n", curr->data);
		free(curr);
		curr = h->next;
	}
	free(h);
}

void removeNode(Dnode* h, Dnode* p)
{
	Dnode* curr = h->next;

	while (curr != p) 
	{
		curr = curr->next;
	}
	if (curr->prev == NULL) //���� NULL�ϰ�� 
	{
		curr->next->prev = curr->prev;
		h->next = curr->next;
	}
	else if (curr->next == NULL) //�ڰ� NULL�ϰ��
	{
		curr->prev->next = curr->next;
	}
	else //�Ϲ����� ��� 
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}
	free(curr);

}