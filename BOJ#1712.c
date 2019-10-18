//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1712 손익분기점
//

#include <stdio.h>
int main(void)
{
	int A, B, C;
	register int ret, profit;
	scanf("%d %d %d", &A, &B, &C);
	profit = C - B;
	if (profit < 1) ret = -1;
	else ret = A / profit + 1;
	printf("%d", ret);
	return 0;
}