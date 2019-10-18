//
//	OS Windows
//	2019.10.03
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1008 A / B
//

#include <stdio.h>
int main(void)
{
	freopen("input1008.txt", "r", stdin);
	double A, B;
	scanf("%lf %lf", &A, &B);
	printf("%.9f", A / B);
	return 0;
}