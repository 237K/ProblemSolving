//
//	OS Windows
//	2020.05.22
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1971> �ּҰ��� ��ġ ���
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
int arr[SZ], N, min;
int main(void)
{
	min = 1001;
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		if (min > arr[i]) min = arr[i];
	}
	for (i = 0; i < N; ++i)
	{
		if (arr[i] == min)
			printf("%d ", i + 1);
	}
	return 0;
}