#include <stdio.h>
#include <stdlib.h>

//�迭 �޸� �����Ҵ�
int main() 
{
	int size;
	printf("���� ������ �Է��ϼ���: ");
	scanf("%d", &size);
	printf("%d ���� ���� ���� �迭�� ����ϴ�. ", size);

	int* arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL)
		return -1;

	for (int i = 0; i < size; i++) {
		scanf("%d", arr + i); // &arr[i] == arr+ i
	}

	for (int i = 0; i < size; i++) {
		printf("%d\n", *(arr + i)); // arr[i] == *(arr + i)
	}

	free(arr);
	return 0;
}