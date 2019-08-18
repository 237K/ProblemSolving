//
//	OS Windows
//	2019.08.17
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8338] (D3) °è»ê±â
//
//	ver.2
//

#include <stdio.h>
int arr[9];
int T, N;
int simul()
{
	register int ret, i;
	ret = arr[0];
	for (i = 1; i < N; ++i)
	{
		if (ret < 2 || arr[i] < 2) ret += arr[i];
		else ret *= arr[i];
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