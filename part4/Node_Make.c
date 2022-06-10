#include <stdio.h>

typedef struct _note {
	int data;
	struct _node* next;
}Node;

void addNode(Node* h, int d)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = d;
	NewNode->next = h->next;
	h->next = NewNode;

}

void printfNode(Node* h) 
{
	Node* curr = h->next;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

}
int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	addNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	printfNode(head);
	return 0;
}
