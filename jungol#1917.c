//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1917> ���ʰ��
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 500
int cost[SZ], N, Q, start, end;
int main(void)
{
	scanf("%d %d", &N, &Q);
	register int n, q, i, sum;
	for (n = 0; n < N; ++n)
		scnaf("%d", &cost[n]);
	for (q = 0; q < Q; ++q)
	{
		scanf("%d %d", &start, &end);
		start--; end;
		sum = 0;
		for (i = start; i < end; ++i)
			sum += cost[i];
		printf("%d\n", sum);
	}
	return 0;
}