//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1047> 피보나치수열1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 41
int arr[SZ], N, i;
int main(void)
{
	arr[0] = arr[1] = arr[2] = 1;
	scanf("%d", &N);
	for (i = 3; i <= N; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];
	printf("%d", arr[N]);
	return 0;
}