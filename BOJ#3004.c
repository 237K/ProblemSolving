//
//	OS Windows
//	2019.11.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3004	체스판 조각
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input3004.txt", "r", stdin);
	int N;
	register int r, c;
	scanf("%d", &N);
	r = N / 2; c = N - r;
	printf("%d", ++r * ++c);
	return 0;
}