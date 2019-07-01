//
//	OS Windows
//	2019.07.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1986] (D2) 지그재그 숫자
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ret[11];
int main(void)
{
	int T, N;
	register int tc, i;
	scanf("%d", &T);
	ret[1] = 1;
	for (i = 2; i <= 10; ++i)
	{
		if (!(i % 2)) ret[i] = ret[i - 1] - i;
		else ret[i] = ret[i - 1] + i;
	}
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		printf("#%d %d\n", tc, ret[N]);
	}
	return 0;
}