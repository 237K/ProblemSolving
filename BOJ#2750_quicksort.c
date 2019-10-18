//
//	OS Windows
//	2019.10.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2750 수 정렬하기
//

#include <stdio.h>
void print(int arr[], int n)
{
	for (register int i = 0; i < n; ++i) printf("%d\n", arr[i]);
}
void swap(int arr[], int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
int partition(int arr[], int left, int right)
{
	register int pivot, low, high;
	pivot = left;
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (arr[pivot] >= arr[low] && low <= high)
		{
			low++;
		}
		while (arr[pivot] <= arr[high] && low <= high)
		{
			high--;
		}
		if(low <= high)
			swap(arr, low, high);
	}
	swap(arr, pivot, high);
	return high;
}
void quick_sort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}
int main(void)
{
	freopen("input2750.txt", "r", stdin);
	int N, n;
	int arr[1001];
	scanf("%d", &N);
	for (n = 0; n < N; ++n) scanf("%d", &arr[n]);
	quick_sort(arr, 0, N - 1);
	print(arr, N);
	return 0;
}