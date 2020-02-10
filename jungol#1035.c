//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1035> 최대값
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 9
int main(void)
{
	int cur, i, high = 0, idx;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &cur);
		if (high < cur)
		{
			idx = i + 1;
			high = cur;
		}
	}
	printf("%d\n%d", high, idx);
	return 0;
}