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
#define MAX 20
int N, L;
int S[MAX], K[MAX];
int max_score;

void comb(int cnt, int idx, int score, int cal)
{
	if (cnt > N || cal > L) return;
	if (cnt >= 2)
		if (max_score < score) max_score = score;
	for (register int i = idx; i < N; ++i)
	{
		if (K[i] > L) comb(cnt, i + 1, score, cal);
		else comb(cnt + 1, i + 1, score + S[i], cal + K[i]);
	}
}

int main(void)
{
	freopen("s_input5215.txt", "r", stdin);
	int T, tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		max_score = 0;
		scanf("%d %d", &N, &L);
		for (n = 0; n < N; ++n)
		{
			scanf("%d %d", &S[n], &K[n]);
			if (K[n] <= L && max_score < S[n]) max_score = S[n];
		}
		comb(0, 0, 0, 0);
		printf("#%d %d\n", tc, max_score);
	}
	return 0;
}