#include <stdio.h>

//����Լ�
int Recursive( int num)
{
	if (num <= 0)
		return;

	printf("Recursive call! %d \n", num);
	Recursive(num - 1);
}

int main() 
{
	Recursive(3);
	return 0;
}