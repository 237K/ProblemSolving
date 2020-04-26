//
//	OS Windows
//	2020.04.26
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1805> 카드게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int main(void)
{
	int i, in, sum = 0;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &in);
		sum += in;
	}
	printf("%d", sum);
	return 0;
}