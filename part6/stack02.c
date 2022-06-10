// 순차리스트 배열구현

#include <stdio.h>
#include <Stdbool.h>

#define STACK_SZ 10
typedef int element;

typedef struct {
	int top;
	element stack[STACK_SZ];
}Stack;

void initStack(Stack* pstack);
bool isEmpty(Stack* pstack);
bool isFull(Stack* pstack);
void push(Stack* pstack, element value);
element pop(Stack* pstack);
//element peek(Stack* pstack);

int main()
{
	Stack stack;
	initStack(&stack);
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);

	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	return 0;
}

void initStack(Stack* pstack)
{
	pstack->top = -1;
}

bool isEmpty(Stack* pstack)
{
	if (pstack->top <= -1) return 1;
	else return 0;
}

bool isFull(Stack* pstack)
{
	if (pstack->top >= STACK_SZ - 1) return 1;
	else return 0;
}

void push(Stack* pstack, element value)
{
	if (isFull(pstack))
	{
		printf("스택이 포화상태입니다.\n");
		return;
	}
	else
	{
		pstack->top++;
		return pstack->stack[pstack->top] = value;
	}
}

element pop(Stack* pstack)
{
	if (isEmpty(pstack))
	{
		printf("스택이 비었습니다.\n");
		return 0;
	}
	else
	{
		return pstack->stack[pstack->top--];
	}
}