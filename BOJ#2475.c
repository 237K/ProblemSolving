//
//	OS Windows
//	2020.01.02
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2475>	검증수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int main(void)
{
	int n, i, nn, sum = 0;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &n);
		nn = n * n;
		sum += nn;
	}
	printf("%d", sum % 10);
	return 0;
}