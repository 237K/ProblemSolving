//
//	OS Windows
//	2020.01.06
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2523>	º° Âï±â - 13
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input2523.txt", "r", stdin);
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N * 2 - 1; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (i < N)
			{
				if (i >= j) printf("*");
				else printf(" ");
			}
			else
			{
				if (2*N-1-i > j) printf("*");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}