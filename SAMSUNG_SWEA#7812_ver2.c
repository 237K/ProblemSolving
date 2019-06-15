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

int simul()
{
	register int i, j, ret = 0, tmp;
	for (i = 0; i < N; ++i)
	{
		if (land[i] > M) continue;
		if (land[i] == M)
		{
			ret++;
			continue;
		}
		tmp = land[i];
		for (j = 1; j < N; ++j)
		{
			tmp += land[i + j];
			if (tmp > M) break;
			if (tmp == M)
			{
				ret++;
				break;
			}
		}
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