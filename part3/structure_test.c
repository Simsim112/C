#include <stdio.h>
#include <stdlib.h>

#define size 2

typedef struct Employee {
	int id;
	char* name;
	int pay;
}employee;

employee s1[size];

int main()
{
	int sum = 0;
	float avg = 0;
	char temp[100];

	for (int i = 0; i < size; i++) {
		printf("-------------------------------------------\n");

		printf("�����ȣ�� �Է����ּ���: ");
		scanf("%d", &s1[i].id);

		getchar();
		printf("�̸��� �Է����ּ���: ");
		gets(temp);
		s1[i].name = (char*)malloc(strlen(temp) + 1); //NULL���� +1?? / �е�����
		strcpy(s1[i].name, temp);

		printf("�޿��� �Է����ּ���: ");
		scanf("%d", &s1[i].pay);
	}

	for (int i = 0; i < size; i++)
	{
		sum += s1[i].pay;

	}
	avg = sum / size;

	for (int i = 0; i < size; i++)
	{
		printf("%d %s %d\n", s1[i].id, s1[i].name, s1[i].pay);
	}

	printf("\n�ѱ޿�: %d \n��ձ޿�: %.1f", sum, avg);

	for (int i = 0; i < size; i++)
	{
		free(s1[i].name);
	}

	return 0;
}