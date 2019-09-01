//
//	OS Windows
//	2019.08.23
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2783	»ï°¢ ±è¹ä
//

#include <stdio.h>
int main(void)
{
	freopen("input2783.txt", "r", stdin);
	int N, n, X, Y;
	double cur, tmp;
	scanf("%d %d\n%d", &X, &Y, &N);
	cur = (double)X / (double)Y;
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d", &X, &Y);
		tmp = (double)X / (double)Y;
		if (cur > tmp) cur = tmp;
	}
	cur *= (double)1000;
	printf("%.2f", cur);
	return 0;
}