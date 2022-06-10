
#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
	int data;			//데이터를 저장할 멤버 변수
	struct _node* next; //주소를 저장할 포인터 멤버 변수 
}Node;

int main()
{
	/*Node Node1, Node2;
	Node1.data = 10;
	Node1.next = &Node2;

	Node2.data = 20;
	Node2.next = NULL;

	printf("%d %p \n", Node1.data, Node1.next);
	printf("%d %p \n", Node2.data, Node2.next);
	printf("%p", &Node2);*/

	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) return;
	head->next = NULL;

	Node* Node1 = (Node*)malloc(sizeof(Node));
	if (Node1 == NULL) return;
	Node1->data = 10;
	Node1->next = NULL;
	head->next = Node1;

	Node* Node2 = (Node*)malloc(sizeof(Node));
	if (Node2 == NULL) return;
	Node2->data = 20;
	Node2->next = NULL;

	Node* Node3 = (Node*)malloc(sizeof(Node));
	if (Node3 == NULL) return;
	Node3->data = 30;
	Node3->next = NULL;
	
	Node* Node4 = (Node*)malloc(sizeof(Node));
	if (Node4 == NULL) return;
	Node4->data = 40;
	Node4->next = NULL;

	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;

	Node* curr = head->next;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}


	free(Node4);
	free(Node3);
	free(Node2);
	free(Node1);
	free(head);
	return 0;
}