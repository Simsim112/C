#include <stdio.h>
#include <stdlib.h>

//배열 메모리 동적할당
int main() 
{
	int size;
	printf("방의 개수를 입력하세요: ");
	scanf("%d", &size);
	printf("%d 개의 방을 갖는 배열을 만듭니다. ", size);

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