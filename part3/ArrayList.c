#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	(plist->numofData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numofData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	} 

	plist->arr[plist->numofData] = data;
	(plist->numofData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numofData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numofData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpose = plist->curPosition;
	int num = plist->numofData;
	int i;
	LData rdata = plist->arr[rpose];

	for (i = rpose; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numofData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numofData;
}