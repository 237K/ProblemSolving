//
//	OS Windows
//	2019.09.21
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10818 최소, 최대
//

#include <stdio.h>
int main(void)
{
	int N, i, n, mi = 2147000000, ma = -2147000000;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &n);
		if (mi > n) mi = n;
		if (ma < n) ma = n;
	}
	printf("%d %d", mi, ma);
	return 0;
}