//
//	OS Windows
//	2020.02.11
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1146> 선택정렬
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
int arr[SZ], N;
void print()
{
	register int i;
	for (i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
void swap(int idx1, int idx2)
{
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}
void selection_sort()
{
	register int i, j, idx, lower;
	for (i = 0; i < N-1; ++i)
	{
		lower = arr[i];
		idx = i;
		for (j = i+1; j < N; ++j)
		{
			if (lower > arr[j])
			{
				lower = arr[j];
				idx = j;
			}
		}
		swap(i, idx);
		print();
	}
}
int main(void)
{
	freopen("jinput1146.txt", "r", stdin);
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	selection_sort();
	return 0;
}