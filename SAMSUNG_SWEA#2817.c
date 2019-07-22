//
//	OS Windows
//	2019.07.22
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2817] (D3) 부분 수열의 합
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[20];
int pick[20];
int T, N, K, ret;
void sol(int cnt, int idx)
{
	if (cnt > 0)
	{
		register int i, sum = 0;
		for (i = 0; i < cnt; ++i)
		{
			sum += arr[pick[i]];
		}
		if (sum == K)
		{
			ret++;
			return;
		}
	}
	for (register int j = idx; j < N; ++j)
	{
		pick[cnt] = j;
		sol(cnt + 1, j + 1);
	}
}
int main(void)
{
	freopen("s_input2817.txt", "r", stdin);
	register int tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		ret = 0;
		scanf("%d %d", &N, &K);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &arr[i]);
		}
		sol(0, 0);
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}