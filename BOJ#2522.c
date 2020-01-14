//
//	OS Windows
//	2020.01.02
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2522>	º° Âï±â - 12
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
char ret[SZ*2][SZ];
int main(void)
{
	freopen("input2522.txt", "r", stdin);
	int N, r, c;
	scanf("%d", &N);
	for (r = 0; r < N*2-1; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (r < N)
			{
				if (c >= N - r - 1) printf("*");
				else printf(" ");
			}
			else
			{
				if (c > r - N) printf("*");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}