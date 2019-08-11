//
//	OS Windows
//	2019.08.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8275] (D4) «‹Ω∫≈Õ
//

#include <stdio.h>
#include <memory.h>
int cage[11], ret[11];
int lower[11], upper[11], low_to_upper_sum[11];
int check[11];
int T, N, X, M, flag;
int test()
{
	register int n, left, right, tmp, i;
	for (n = 0; n < M; ++n)
	{
		tmp = 0; left = lower[n]-1; right = upper[n]-1;
		for (i = left; i <= right; ++i)
		{
			tmp += cage[i];
		}
		if (tmp != low_to_upper_sum[n]) return 0;
	}
	return 1;
}
void comb(int cnt)
{
	if (flag) return;
	if (cnt == N)
	{
		for (register int p = 0; p < N; ++p) printf("%d ", cage[p]);
		printf("\n\n");
		int flag = 0;
		if (test())
		{
			(void)memcpy(ret, cage, sizeof(cage));
			flag = 1;
		}
		return;
	}
	for (register int i = 0; i <= X; ++i)
	{
		cage[cnt] = i;
		comb(cnt + 1);
	}
}
int main(void)
{
	freopen("s_input8275.txt", "r", stdin);
	register int tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(check, 0, sizeof(check)); flag = 0;
		scanf("%d %d %d", &N, &X, &M);
		for (n = 0; n < M; ++n)
		{
			scanf("%d %d %d", &lower[n], &upper[n], &low_to_upper_sum[n]);
		}
		comb(0);
		printf("#%d ", tc);
		if (flag) for (n = 0; n < N; ++n) printf("%d ", ret[n]);
		else printf("-1");
		printf("\n");
	}
	return 0;
}