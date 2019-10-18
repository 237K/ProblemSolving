//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2438 º° Âï±â-1
//

#include <stdio.h>
int main(void)
{
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}