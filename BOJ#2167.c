//
//	OS Windows
//	2019.12.26
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2167>	2차원 배열의 합
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 301
int map[SZ][SZ], N, M, K, x1, x2, y1, y2;
int main(void)
{
	freopen("input2167.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int r, c, k, sum;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			scanf("%d", &map[r][c]);
		}
	}
	scanf("%d", &K);
	for (k = 0; k < K; ++k)
	{
		sum = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (r = x1 - 1; r < x2; ++r)
		{
			for (c = y1 - 1; c < y2; ++c)
			{
				sum += map[r][c];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}