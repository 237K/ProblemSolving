//
//	OS Windows
//	2019.06.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7812] (D5) ø¡»Ò¿« OK! ∫ŒµøªÍ
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

int N, M;
int land[MAX];
int comb[MAX];

int search(int cnt, int i, int cost)
{
	if (cost > M) return 0;
	if (cnt >= N) return 0;
	if (comb[cnt - 1] != i - 1) return 0;
	if (cost == M) return 1;
	if (cost + land[i] <= M)
	{
		comb[cnt] = i;
		return search(cnt + 1, i + 1, cost + land[i]);
	}
}
int simul()
{
	register int i, ret = 0, tmp;
	for (i = 0; i < N; ++i)
	{
		if (land[i] == M)
		{
			ret++;
			continue;
		}
		if (land[i] > M) continue;
		comb[0] = i;
		tmp = search(1, i + 1, land[i]);
		if (!tmp) continue;
		else if (tmp == 1) ret++;
	}
	return ret;
}
int main(void)
{
	freopen("s_input7812.txt", "r", stdin);
	int T;
	register int tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &M);
		for (n = 0; n < N; ++n) scanf("%d ", &land[n]);
		printf("#%d %d\n", tc, simul());
	}
	return 0;
}