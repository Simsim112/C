#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 5

typedef int element;		//�����ڷ���

bool isEmpty();
bool isFULL();
void push(element value);
element pop();
element peek();

element stack[STACK_SZ];	//����
int top = -1;				// -1�̸� ������ִ�.

int main()
{


	return 0;
}

bool isEmpty()		//������ִ��� Ȯ�� 
{
	if (top <= -1) return true;
	else return false;
}

bool isFULL()		//������ ��ȭ���� Ȯ��
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}

void push(element value)	//���ÿ��� ����
{
	if (isFULL())
	{
		printf("������ ��ȭ�����Դϴ�.\n");
		return;
	}
	else stack[++top] = value;		//top�� �ʱⰪ�� -1�̹Ƿ� 
}

element pop()		//���ÿ��� ��� 
{
	if (isEmpty())
	{
		printf("������ ����ֽ��ϴ�.\n");
		return 0;
	}
	else return stack[top--];
}

element peek()
{
	if (isEmpty())
	{
		printf("������ ����ֽ��ϴ�.\n");
		exit(1);
	}
	else return stack[top];
}