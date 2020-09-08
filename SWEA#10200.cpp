//
//	OS Windows
//	2020.09.08
//
//	[Algorithm Problem Solving]
//
//	SWEA [#10200] (D3) 구독자 전쟁
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int T, N, A, B;
	register int tc, min, max, tmp;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d %d", &N, &A, &B);
		if (A > B) min = B;
		else min = A;
		tmp = A + B - N;
		if (tmp < 0) tmp = 0;
		if (min > tmp)
		{
			max = min;
			min = tmp;
		}
		else
		{
			max = tmp;
		}
		printf("#%d %d %d\n", tc, max, min);
	}
	return 0;
}