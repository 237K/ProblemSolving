//
//	OS Windows
//	2019.07.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7964] (D3) ºÎ¸Ô¿Õ±¹ÀÇ Â÷¿ø °ü¹®
//

#include <stdio.h>
int main(void)
{
	int T, N, D, C;
	register int tc, n, cnt, quo, rmd, ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &D);
		cnt = ret = 0;
		for (n = 0; n < N; ++n)
		{
			scanf("%d", &C);
			if (!C) cnt++;
			else
			{
				if (cnt)
				{
					quo = cnt / D;
					ret += quo;
				}
				cnt = 0;
			}
		}
		if (cnt >= D)
		{
			quo = cnt / D;
			ret += quo;
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}