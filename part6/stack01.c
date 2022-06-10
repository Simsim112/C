#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 5

typedef int element;		//스택자료형

bool isEmpty();
bool isFULL();
void push(element value);
element pop();
element peek();

element stack[STACK_SZ];	//스택
int top = -1;				// -1이면 비워져있다.

int main()
{


	return 0;
}

bool isEmpty()		//비워져있는지 확인 
{
	if (top <= -1) return true;
	else return false;
}

bool isFULL()		//스택의 포화상태 확인
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}

void push(element value)	//스택원소 삽입
{
	if (isFULL())
	{
		printf("스택이 포화상태입니다.\n");
		return;
	}
	else stack[++top] = value;		//top의 초기값이 -1이므로 
}

element pop()		//스택원소 출력 
{
	if (isEmpty())
	{
		printf("스택이 비어있습니다.\n");
		return 0;
	}
	else return stack[top--];
}

element peek()
{
	if (isEmpty())
	{
		printf("스택이 비어있습니다.\n");
		exit(1);
	}
	else return stack[top];
}