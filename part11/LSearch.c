#include <stdio.h>

int LSearch(int * arry, int adata, int arry_num);
int main()
{
	int ary[] = { 1,5,9,3,8,7,4,2 };
	int data, res;
	int arry_num = sizeof(ary) / sizeof(int);
	printf("ã�� ���ڸ� �Է��ϼ���: ");
	scanf("%d", &data);
	res = LSearch(ary, data, arry_num);
	if (res == 0) printf("ã�� ���ڰ� �����ϴ�.\n");
	else printf("%d�� ã�ҽ��ϴ�.", res);
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