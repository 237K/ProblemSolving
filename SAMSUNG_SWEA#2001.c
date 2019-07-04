//
//	OS Windows
//	2019.07.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2001] (D2) ÆÄ¸® ÅðÄ¡
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 15
int T, N, M;
int map[SZ][SZ];
int sol()
{
	register int tmp, ret = 0, r, c, i, j, cr, cc, limit = 30 * M * M;
	for (r = 0; r <= N - M + 1; ++r)
	{
		for (c = 0; c <= N - M + 1; ++c)
		{
			tmp = 0;
			for (i = 0; i < M; ++i)
			{
				for (j = 0; j < M; ++j)
				{
					cr = r + i; cc = c + j;
					tmp += map[cr][cc];
				}
			}
			if (tmp == limit) return tmp;
			if (ret < tmp) ret = tmp;
		}
	}
	return ret;
}
int main(void)
{
	register int tc, r, c;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &M);
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				scanf("%d", &map[r][c]);
			}
		}
		printf("#%d %d\n", tc, sol());
	}
	return 0;
}