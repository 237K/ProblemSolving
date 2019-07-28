//
//	OS Windows
//	2019.07.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1966] (D2) 숫자를 정렬하자
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int T, N;
int arr[51];
void Swap(int idx1, int idx2)
{
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}
int Partition(int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right) low++;
		while (pivot <= arr[high] && high >= (left+1)) high--;
		if (low <= high) Swap(low, high);
	}
	Swap(left, high);
	return high;
}
void quick_sort(int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(left, right);
		quick_sort(left, pivot - 1);
		quick_sort(pivot + 1, right);
	}
}
int main(void)
{
	freopen("input1966.txt", "r", stdin);
	register int tc, i, tmp;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%d", &arr[i]);
		quick_sort(0, N - 1);
		printf("#%d ", tc);
		for (i = 0; i < N; ++i) printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}