#include <stdio.h>

int LSearch(int * arry, int adata, int arry_num);
int main()
{
	int ary[] = { 1,5,9,3,8,7,4,2 };
	int data, res;
	int arry_num = sizeof(ary) / sizeof(int);
	printf("찾을 숫자를 입력하세요: ");
	scanf("%d", &data);
	res = LSearch(ary, data, arry_num);
	if (res == 0) printf("찾는 숫자가 없습니다.\n");
	else printf("%d를 찾았습니다.", res);
	return 0;
}

int LSearch(int* arry, int adata, int arry_num) 
{
	int i = 0;

	for (i = 0; i < arry_num; i++) {
		if (adata == arry[i])
			return arry[i];
	}
	return 0;
		
}