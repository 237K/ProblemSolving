//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1072> 연속된 최대값
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
int arr[SZ], N, M, sum, upper;
int main(void)
{
	register int i, j;
	upper = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	for (i = 0; i <= N - M; ++i)
	{
		sum = 0;
		for (j = i; j < i + M; ++j)
		{
			sum += arr[j];
		}
		if (upper < sum) upper = sum;
	}
	printf("%d", upper);
	return 0;
}