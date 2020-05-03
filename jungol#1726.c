//
//	OS Windows
//	2020.04.24
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1726> 구간의 최대값1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 50000
int arr[SZ], Q, N, A, B, max;
int main(void)
{
	register int n, q, i;
	scanf("%d %d", &N, &Q);
	for (n = 0; n < N; ++n)
		scanf("%d", &arr[n]);
	for (q = 0; q < Q; ++q)
	{
		max = 0;
		scanf("%d %d", &A, &B);
		for (i = A - 1; i < B; ++i)
		{
			if (max < arr[i])
				max = arr[i];
		}
		printf("%d\n", &max);
	}
	return 0;
}