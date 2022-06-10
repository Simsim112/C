#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) //피벗이 제일 처음있을 경우 
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot > arr[low])
			low++;
		while (pivot < arr[high])
			high--;
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

void QuickSort2(int arr[], int left, int right) //피벗을 중간값을 가질 경우 
{
	int lidx = left, ridx = right;
	int temp;
	int pivot = arr[(left + right) / 2];

	while (lidx <= ridx)
	{
		while (arr[lidx] < arr[pivot])
			lidx++;
		while (arr[ridx] > arr[pivot])
			ridx--;
		if (lidx < ridx) {
			Swap(arr, lidx, ridx);
		}
		lidx++;
		ridx--;
	}
	if (left < ridx) QuickSort2(arr, left, ridx);
	if (lidx < right) QuickSort2(arr, lidx, right);
}
int main()
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	//int arr[3] = { 3,3,3 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort2(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d", arr[i]);

	printf("\n");
	return 0;
}