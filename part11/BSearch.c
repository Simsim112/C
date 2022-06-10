#include <stdio.h>

int BSearch(int* ary, int alen, int akey)
{
	int first = 0;
	int last = alen - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (akey == ary[mid])
			return mid;
		else {
			if (akey < ary[mid]) {
				last = mid - 1;
			}
			else{
				first = mid + 1 ;
			}

		}
	}
	return -1;
}

int main()
{
	int ary[] = { 1,3,4,5,7,8,9 };
	int len = sizeof(ary) / sizeof(ary[0]);
	int key, idx;

	printf("검색값 입력 :");
	scanf("%d", &key);
	idx = BSearch(ary, len, key);
	if (idx == -1) printf("없습니다.\n");
	else printf("key index : %d", idx);

	return 0;
}