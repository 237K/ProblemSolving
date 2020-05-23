//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1917> 건초경비
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 500
int cost[SZ], N, Q, START, END;
int main(void)
{
	scanf("%d %d", &N, &Q);
	register int n, q, i, sum;
	for (n = 0; n < N; ++n)
		scanf("%d", &cost[n]);
	for (q = 0; q < Q; ++q)
	{
		scanf("%d %d", &START, &END);
		START--;
		sum = 0;
		for (i = START; i < END; ++i)
			sum += cost[i];
		printf("%d\n", sum);
	}
	return 0;
}