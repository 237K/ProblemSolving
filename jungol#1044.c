//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1044> �ִ밪 - �ּҰ�
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10
int main(void)
{
	int n, i, upper, lower;
	upper = 0;
	lower = 3001;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &n);
		if (upper < n) upper = n;
		if (lower > n) lower = n;
	}
	printf("%d", upper - lower);
	return 0;
}