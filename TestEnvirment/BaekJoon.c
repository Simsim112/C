#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) // 에러 발생시
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) // 노드의 삽입
{
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void display(ListNode* head) // 리스트 출력
{
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

ListNode* insertion_sort(ListNode* phead)
{
	ListNode* p, * temp;
	p = phead;

	while (p->link != NULL) {
		if (p->data > p->link->data)
		{
			temp = p->link; // 앞으로 옮겨야할 노드를 temp에 저장
			p->link = p->link->link; // temp에 저장한 놈을 빼고 연결 합니다.
			temp->link = phead; // temp의 link는 가장 첫 자리를 가리킵니다.
			phead = p = temp; // 그리고 p와 phead 모두 temp로 초기화 함으로 써 모두 가장 첫자리로 가게 됩니다.
			display(phead); // 변하는 과정
			printf("\n");
			continue; // 가장 첫 자리로 간 p가 밑의 p = p->link로 인해서 앞으로 가지 못하도록 막는 역할을 합니다.
		}
		p = p->link;
	}
	return phead;
}

ListNode* create_node(element data, ListNode* link) // 노드를 만드는 함수
{
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

int main(void)
{
	ListNode* list1 = NULL;
	int i;
	for (i = 0; i < 8; i++)
		insert_node(&list1, NULL, create_node(rand() % 15, NULL)); // 8개의 리스트에 랜덤으로 수를 넣는 반복문
	list1 = insertion_sort(list1); // 정렬해서 list1에 집어 넣음
	printf("------최종 정렬------\n");
	display(list1); // 정렬 된 모습을 출력

	return 0;
}

