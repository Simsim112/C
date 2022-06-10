#include <stdio.h>

// 5개의 정수를 입력받아 최대값 찾기 
int main() 
{
	int a[5];
	int bigger = 0;

	fputs("안녕하세요", stdout);
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