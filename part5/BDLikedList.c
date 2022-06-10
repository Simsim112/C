#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
	int data;
	struct dnode* next;
	struct dnode* prev;
}Dnode;

void insertNode(Dnode*, int, Dnode*, char); //맨마지막 옵션 n p 앞 뒤 연결
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
	Dnode* pos = NULL;		//기준노드, 검색노드의 주소를 저장 

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
		if (p == NULL)					//첫번째 노드로 삽입
		{
			newNode->next = h->next;
			if (h->next != NULL)		//기존리스트가 있을 경우 
			{
				newNode->next->prev = newNode;
			}
			h->next = newNode;		    //기존리스트가 아무것도 없을경우 
		}
		else {							//원하는 위치에다가 집어넣을경우 
			Dnode* curr = h->next;
			while (curr != p)
			{
				curr = curr->next;
			}

			if (opt == 'p') //전위 삽입 
			{
				newNode->prev = curr->prev;
				newNode->next = curr;
				if (newNode->prev != NULL)
					newNode->prev->next = newNode;
				else
					h->next = newNode;				//넣으려는 앞노드가 head일 경우 
				curr->prev = newNode;
			}
			else if (opt == 'n') //후위 삽입 
			{
				newNode->next = curr->next;
				newNode->prev = curr;
				if (curr->next != NULL)
					curr->next->prev = newNode;  //마지막노드가 아닌경우 
				curr->next = newNode;
			}
		}
	}
}

void printNode(Dnode* h) 
{
	Dnode* curr = h->next;
	if (h->next == NULL) {
		printf("리스트가 비어있습니다.\n");
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
	printf("찾는 값이 없습니다.\n");
	return -1;
}

void allDelNode(Dnode* h) 
{
	Dnode* curr = h->next;

	while (curr != NULL)
	{
		h->next = curr->next;
		//printf("%d를 삭제합니다.\n", curr->data);
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
	if (curr->prev == NULL) //앞이 NULL일경우 
	{
		curr->next->prev = curr->prev;
		h->next = curr->next;
	}
	else if (curr->next == NULL) //뒤가 NULL일경우
	{
		curr->prev->next = curr->next;
	}
	else //일반적인 경우 
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}
	free(curr);

}