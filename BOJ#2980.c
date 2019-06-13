//
//	OS Windows
//	2019.06.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2980	도로와 신호등
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input2980.txt", "r", stdin);
	int N, L, D, R, G;
	register int n, cycle, idx, tik = 0, l = 0;
	scanf("%d %d", &N, &L);
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d %d", &D, &R, &G);
		tik += D - l; l = D;
		cycle = R + G;
		idx = tik % cycle;
		if (idx <= R) tik += R - idx;
	}
	if (l < L) tik += L - l;
	printf("%d\n", tik);
	return 0;
}