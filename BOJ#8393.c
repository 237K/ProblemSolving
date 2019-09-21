//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #8393 гу
//
#include <stdio.h>
int main(void)
{
	int n, i, r = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) r += i;
	printf("%d", r);
}