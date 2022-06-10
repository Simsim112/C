/*
	AlPhabet_sort.c
	created : 2022. 3. 3
	Author : �ɹ���
*/

#include <stdio.h>
#include <stdlib.h>

//��� ����ü
typedef struct node {
	char data;
	struct node* next;
}Node;

//�׳� ���, ���Ŀ� ��� 
struct node* head = NULL;
struct node* sorted = NULL;

//��� ���� 
void createaNode(char val)
{

	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->next = head;
	head = newnode;
}


//���� ���� 
void sortedInsert(Node* newnode)
{

	if (sorted == NULL || sorted->data >= newnode->data) {
		newnode->next = sorted;
		sorted = newnode;
	}
	else {
		Node* current = sorted;

		while (current->next != NULL && current->next->data < newnode->data) {
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
}

//�������ؼ� �ϳ��� �־��ֱ� 
void insertionSort()
{

	Node* current = head;

	while (current != NULL) {

		Node* next = current->next;
		sortedInsert(current);
		current = next;
	}

	head = sorted;
}

//��� 
void printlist(Node* head)
{
	while (head != NULL) {
		printf("%c ", head->data);
		head = head->next;
	}
}

int main()
{
	char data = NULL;
	int LOOP_CHECK = 1;

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
			createaNode(data);
		}
		else
		{
			printf("���ڰ� �ƴմϴ�.\n");
		}
	}

	insertionSort(head);
	printlist(head);
}