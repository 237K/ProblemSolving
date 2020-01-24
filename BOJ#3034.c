//
//	OS Windows
//	2019.11.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3034	¾Þ±×¸® Ã¢¿µ
//	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input3034.txt", "r", stdin);
	int N, W, H, D, E, F;
	register int n;
	scanf("%d %d %d", &N, &W, &H);
	D = W * W + H * H;
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &E);
		F = E * E;
		if (D >= F) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}