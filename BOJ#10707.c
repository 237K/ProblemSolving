//
//	OS Windows
//	2019.08.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10707	수도요금
//

#include <stdio.h>
int main(void)
{
	int A, B, C, D, P, X, Y;
	scanf("%d\n%d\n%d\n%d\n%d", &A, &B, &C, &D, &P);
	X = A * P;
	if (P <= C) Y = B;
	else Y = B + ((P - C) * D);
	if (X > Y) X = Y;
	printf("%d", X);
	return 0;
}