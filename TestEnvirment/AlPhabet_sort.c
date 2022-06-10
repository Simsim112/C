/*
	AlPhabet_sort.c
	created : 2022. 3. 3
	Author : 심무성
*/

#include <stdio.h>
#include <stdlib.h>

//노드 구조체
typedef struct node {
	char data;
	struct node* next;
}Node;

//그냥 헤드, 정렬용 헤드 
struct node* head = NULL;
struct node* sorted = NULL;

//노드 생성 
void createaNode(char val)
{

	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->next = head;
	head = newnode;
}


//삽입 정렬 
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

//정렬위해서 하나씩 넣어주기 
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

//출력 
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

	printf("0 을 누르면 입력을 종료합니다.\n");
	while (LOOP_CHECK)
	{
		printf("알파벳 입력 : $ ");
		scanf("%c", &data);
		while (getchar() != '\n');

		if (data == '0')
			LOOP_CHECK = 0;

		if (('A' <= data && data <= 'Z') || ('a' <= data && data <= 'z')) //대문자 || 소문자 
		{
			createaNode(data);
		}
		else
		{
			printf("문자가 아닙니다.\n");
		}
	}

	insertionSort(head);
	printlist(head);
}