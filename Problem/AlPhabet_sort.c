/*
	AlPhabet_sort.c
	created : 2022. 3. 3
	Author : �ɹ���
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��� ����ü
typedef struct _node {
	char data;
	struct _node* next;
}Node;

//���� ����ü
typedef struct _link {
	Node* head;
	Node* tail;
}Link;

Node* createNode(Link* L, char adata);
void printNode(Link* L);
void insertionSort(Link* L);
void insertionSort2(Link* L);

int main()
{
	Link* L = (Link*)malloc(sizeof(Link));
	L->head = NULL;

	//createNode(L, 'a');
	//createNode(L, 'b');
	insertionSort(L);
	printNode(L);
	return 0;
}

//��� ����
Node* createNode(Link* L, char adata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = adata;
	newNode->next = NULL;

	if (L->head == NULL)
	{
		L->head = newNode;
	}
	else
	{
		L->tail->next = newNode;
	}

	L->tail = newNode;

	return newNode;

}

//��� ��ü ���
void printNode(Link* L)
{
	Node* curr = L->head;

	while (curr != NULL)
	{
		printf("%c ", curr->data);
		curr = curr->next;
	};
}

//���� ����(�ڵ尡 �߸�����)
void insertionSort(Link* L)
{
	char data = NULL;
	int LOOP_CHECK = 1;
	int i = 0;
	Node* temp;
	Node* prev1, * last =NULL;
	Node* curr1, * curr2;

	printf("0 �� ������ �Է��� �����մϴ�.\n");
	while (LOOP_CHECK) 
	{
		printf("���ĺ� �Է� : $ ");
		scanf("%c", &data);
		while (getchar() != '\n');

		if (data == '0')
			LOOP_CHECK = 0;

		if (('A' <= data && data <= 'Z') || ('a' <= data && data <= 'z')) //�빮�� || �ҹ��� 
		{
			temp = createNode(L, data);
			curr1 = L->head;
			curr2 = L->head;

			while (curr1 != NULL)
			{
				prev1 = curr1;
				if (temp->data < curr1->data) //�ڿ� �ִ� ���� �� Ŭ ��
				{
					//�� ������ �ּ����� NULL, tail����
					while (curr2->next != NULL) 
					{
						last = curr2;
						curr2 = curr2->next;
					}

					//���簪�� ���� (�ȵ�)
					temp->next = prev1->next;
					prev1->next = temp;

					//�Ǹ�������� NULL����� 
					last->next = NULL;
					L->tail->next = last;
					L->tail = last;
				}
				curr1 = curr1->next;
			};
		}
		else
		{
			printf("���ڰ� �ƴմϴ�.\n");
		}
	}
}

void insertionSort(Link* L)