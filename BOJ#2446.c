//
//	OS Windows
//	2019.12.30
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2446>	º° Âï±â - 9
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 201
char ret[SZ][SZ];
int main(void)
{
	freopen("input2446.txt", "r", stdin);
	int N, r, c;
	scanf("%d", &N);
	for (r = 0; r < 2 * N; ++r)
	{
		for (c = 0; c < 2 * N - 1; ++c)
		{
			if (r < N)
			{
				if (c < r || c >= 2 * N - 1 - r) ret[r][c] = ' ';
				else ret[r][c] = '*';
			}
			else
			{
				ret[r - 1][c] = ret[2 * N - 1 - r][c];
			}
		}
	}
	for (r = 0; r < 2 * N - 1; ++r)
	{
		for (c = 0; c < 2 * N - 1; ++c)
		{
			printf("%c", ret[r][c]);
		}
		printf("\n");
	}
	return 0;
}