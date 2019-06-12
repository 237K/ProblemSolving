//
//	OS Windows
//	2019.06.11
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#4613> (D4) 러시아 국기 같은 깃발
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 51
char map[SZ][SZ];
int color_cnt[SZ][3];
int N, M;
int cnt()
{
	register int w, b, r, n, m, w_cnt, b_cnt, change, ret = 2147000000;
	for (n = 0; n < N; ++n)
	{
		w_cnt = b_cnt = 0;
		for (m = 0; m < M; ++m)
		{
			if (map[n][m] == 'W') w_cnt++;
			else if (map[n][m] == 'B') b_cnt++;
		}
		color_cnt[n][0] = w_cnt; color_cnt[n][1] = b_cnt; color_cnt[n][2] = M - w_cnt - b_cnt;
	}
	for (w = 1; w <= N - 2; ++w)
	{
		for (b = 1; b <= N - w - 1; ++b)
		{
			r = N - w - b; change = 0;
			for (n = 0; n < N; ++n)
			{
				if (change > ret) break;
				if (n < w) change += M - color_cnt[n][0];
				else if (n >= w && n < w+b) change += M - color_cnt[n][1];
				else change += M - color_cnt[n][2];
			}
			if (ret > change) ret = change;
		}
	}
	return ret;
}
int main(void)
{
	freopen("s_input4613.txt", "r", stdin);
	int T;
	register int tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d\n", &N, &M);
		for (n = 0; n < N; ++n) scanf("%s\n", &map[n]);
		printf("#%d %d\n", tc, cnt());
	}
	return 0;
}