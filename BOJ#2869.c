//
//	OS Windows
//	2019.06.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2869	달팽이는 올라가고 싶다
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input2869.txt", "r", stdin);
	int A, B, V, ret = 0, rmd = 0;
	scanf("%d %d %d", &A, &B, &V);
	ret = (V - A) / (A - B) + 1;
	rmd = (V - A) % (A - B);
	if (rmd) ret += 1;
	printf("%d ", ret);
	return 0;
}