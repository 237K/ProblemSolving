//	OS Windows
//	2020.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#10032] (D3) 과자 분배
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int T, N, K;
int main(void)
{
	register int tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &K);
		printf("#%d ", tc);
		if (!(N % K)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}