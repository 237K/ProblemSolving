//
//	OS Windows
//	2019.06.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5215] (D3) 햄버거 다이어트
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000
int N, L;
int S[MAX], K[MAX];

int comb()
{
	int mask, flag, score = 0, max_score = 0, cal = 0;
	for (mask = 1; mask < (1 << N); ++mask)
	{
		score = 0; cal = 0;
		for (flag = 0; flag < N; ++flag)
		{
			if (mask & (1 << flag))
			{
				cal += K[flag];
				if (cal > L) break;
				score += S[flag];
			}
		}
		if (max_score < score) max_score = score;
	}
	return max_score;
}

int main(void)
{
	freopen("s_input5215.txt", "r", stdin);
	int T, tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &L);
		for (n = 0; n < N; ++n)
		{
			scanf("%d %d", &S[n], &K[n]);
		}
		printf("#%d %d\n", tc, comb());
	}
	return 0;
}