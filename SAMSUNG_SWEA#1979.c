//
//	OS Windows
//	2019.07.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1979] (D2) 어디에 단어가 들어갈 수 있을까
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 15
int map[SZ][SZ];
int T, N, K;
int cnt()
{
	register int ret = 0, r, c, col_check, row_check, col_tmp, row_tmp;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			col_tmp = 1;
			if (map[r][c])
			{
				for (col_check = c + 1; col_check < N; ++col_check)
				{
					if (!map[r][col_check]) break;
					col_tmp++;
				}
				if (col_tmp == K) ret++;
				c += col_tmp;
			}
		}
	}
	for (c = 0; c < N; ++c)
	{
		for (r = 0; r < N; ++r)
		{
			row_tmp = 1;
			if (map[r][c])
			{
				for (row_check = r + 1; row_check < N; ++row_check)
				{
					if (!map[row_check][c]) break;
					row_tmp++;
				}
				if (row_tmp == K) ret++;
				r += row_tmp;
			}
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
		scanf("%d %d", &N, &K);
		for (r = 0; r < N; ++r)
			for (c = 0; c < N; ++c)
				scanf("%d", &map[r][c]);
		printf("#%d %d\n", tc, cnt());
	}
	return 0;
}