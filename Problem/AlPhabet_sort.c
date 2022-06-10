/*
	AlPhabet_sort.c
	created : 2022. 3. 3
	Author : 심무성
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//노드 구조체
typedef struct _node {
	char data;
	struct _node* next;
}Node;

//연결 구조체
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

//노드 생성
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

//노드 전체 출력
void printNode(Link* L)
{
	Node* curr = L->head;

	while (curr != NULL)
	{
		printf("%c ", curr->data);
		curr = curr->next;
	};
}

//삽입 정렬(코드가 잘못됬음)
void insertionSort(Link* L)
{
	char data = NULL;
	int LOOP_CHECK = 1;
	int i = 0;
	Node* temp;
	Node* prev1, * last =NULL;
	Node* curr1, * curr2;

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
			temp = createNode(L, data);
			curr1 = L->head;
			curr2 = L->head;

			while (curr1 != NULL)
			{
				prev1 = curr1;
				if (temp->data < curr1->data) //뒤에 있는 값이 더 클 때
				{
					//맨 마지막 주소지를 NULL, tail연결
					while (curr2->next != NULL) 
					{
						last = curr2;
						curr2 = curr2->next;
					}

					//현재값을 연결 (안됨)
					temp->next = prev1->next;
					prev1->next = temp;

					//맨마지막노드 NULL만들기 
					last->next = NULL;
					L->tail->next = last;
					L->tail = last;
				}
				curr1 = curr1->next;
			};
		}
		else
		{
			printf("문자가 아닙니다.\n");
		}
	}
}

void insertionSort(Link* L)