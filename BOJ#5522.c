//
//	OS Windows
//	2020.07.11
//
//	[Algorithm Problem Solving]
//
//	[구현] <BOJ #5522> 카드 게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int main(void)
{
	int i, n, sum = 0;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &n);
		sum += n;
	}
	printf("%d", sum);
	return 0;
}