//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1970] (D2) 쉬운 거스름돈
//

#include <stdio.h>
int main(void)
{
	int T, N;
	register int tc, k50, k10, k5, k1, m5, m1, t5, t1;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		k50 = N / 50000; N %= 50000;
		k10 = N / 10000; N %= 10000;
		k5 = N / 5000; N %= 5000;
		k1 = N / 1000; N %= 1000;
		m5 = N / 500; N %= 500;
		m1 = N / 100; N %= 100;
		t5 = N / 50; N %= 50;
		t1 = N / 10;
		printf("#%d\n%d %d %d %d %d %d %d %d\n", tc, k50, k10, k5, k1, m5, m1, t5, t1);
	}
	return 0;
}