#include <stdio.h>

//n������ ���� ��
//int main() {
//	int a, sum = 0;
//	scanf("%d", &a);
//
//	for (int i = 1; i <= a; i++) {
//		sum += i;
//		printf("%d\n", sum);
//	}
//	printf("%d������ ���� ����: %d", a, sum);
//}

int main() {
	int a, sum;
	scanf("%d", &a);
	 sum = add(a);
	 printf("%d", sum);
}

int add(int i)
{
	if (i == 1) return 1;
	else		return i + add(i-1);
}