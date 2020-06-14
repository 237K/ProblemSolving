//
//	OS Windows
//	2020.06.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#9997] (D3) 미니멀리즘 시계
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define C 2
#define H 60
int T, N, d, h, m;
int main(void)
{
	register int tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		d = N * C;
		h = d / H;
		m = d % H;
		printf("#%d %d %d\n", tc, h, m);
	}
	return 0;
}