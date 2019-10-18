//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2439 º° Âï±â-2
//

#include <stdio.h>
int main(void)
{
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		for (j = N; j >= 1; --j)
		{
			if (i >= j) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}