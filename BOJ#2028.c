//
//	OS Windows
//	2019.12.23
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2028>	자기복제수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int T, N, sz, NN;
int main(void)
{
	freopen("input2028.txt", "r", stdin);
	register int t, tmp;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		scanf("%d", &N);
		NN = N * N;
		tmp = N;
		sz = 1;
		while (tmp)
		{
			sz *= 10;
			tmp /= 10;
		}
		NN %= sz;
		if (N == NN) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}