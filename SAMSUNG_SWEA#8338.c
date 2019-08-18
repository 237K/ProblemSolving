//
//	OS Windows
//	2019.08.17
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8338] (D3) °è»ê±â
//

#include <stdio.h>
int arr[10];
int T, N;
int simul()
{
	register int ret = 0, cur, flag, mask;
	for (mask = 0; mask < (1 << (N-1)); ++mask)
	{
		cur = arr[0];
		for (flag = 0; flag < (N-1); ++flag)
		{
			if ((mask & (1 << flag))) cur *= arr[flag + 1];
			else cur += arr[flag + 1];
		}
		if (ret < cur) ret = cur;
	}
	return ret;
}
int main(void)
{
	freopen("s_input8338.txt", "r", stdin);
	register int tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%d", &arr[i]);
		printf("#%d %d\n", tc, simul());
	}
	return 0;
}