//
//	OS Windows
//	2020.06.04
//
//	[Algorithm Problem Solving]
//
//	[구현] <BOJ#12836> 가계부1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 10001
int cal[SZ], N, Q;
int main(void)
{
	freopen("binput12836.txt", "r", stdin);
	int i, j, k, p, x, q, change;
	(void)memset(cal, 0, sizeof(cal));
	scanf("%d %d", &N, &Q);
	for (i = 0; i < Q; ++i)
	{
		scanf("%d", &j);
		if (j == 1)
		{
			scanf("%d %d", &p, &x);
			cal[p] = x;
		}
		else
		{
			scanf("%d %d", &p, &q);
			change = 0;
			for (k = p; k <= q; ++k)
			{
				change += cal[k];
			}
			printf("%d\n", change);
		}
	}
	return 0;
}