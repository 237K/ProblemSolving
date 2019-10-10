//
//	OS Windows
//	2019.10.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8658] (D3) Summation
//

#include <stdio.h>
int cal(int n)
{
	register int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main(void)
{
	freopen("s_input8658.txt", "r", stdin);
	int T, tc, N, n, maxv, minv, tmp;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		maxv = 0; minv = 2147000000;
		for (n = 0; n < 10; ++n)
		{
			scanf("%d", &N);
			tmp = cal(N);
			if (maxv < tmp) maxv = tmp;
			if (minv > tmp) minv = tmp;
		}
		printf("#%d %d %d\n", tc, maxv, minv);
	}
	return 0;
}