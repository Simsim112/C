#include <stdio.h>

// 5���� ������ �Է¹޾� �ִ밪 ã�� 
int main() 
{
	int a[5];
	int bigger = 0;

	fputs("�ȳ��ϼ���", stdout);
	for (int i = 0; i < 5; i++) 
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		if (bigger < a[i])
			bigger = a[i];
	}
	printf("%d", bigger);

	return 0;
}