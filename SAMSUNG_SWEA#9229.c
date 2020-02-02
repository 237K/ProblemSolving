//
//	OS Windows
//	2020.01.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#9229> (D3) ÇÑºóÀÌ¿Í Spot Mart
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001
int arr[MAX], T, N, M, ret;
void comb(int cnt, int idx, int sum)
{
	if (cnt == 2)
	{
		if (sum <= M)
		{
			if (ret < sum)
				ret = sum;
		}
		return;
	}
	for (register int i = idx; i < N; ++i)
	{
		comb(cnt + 1, i + 1, sum + arr[i]);
	}
}
int main(void)
{
	freopen("s_input9229.txt", "r", stdin);
	register int tc, n, m;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		ret = 0;
		scanf("%d %d", &N, &M);
		for (n = 0; n < N; ++n)
			scanf("%d", &arr[n]);
		comb(0, 0, 0);
		if (!ret) ret = -1;
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}