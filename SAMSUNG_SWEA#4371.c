//
//	OS Windows
//	2019.06.25
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4371] (D3) 항구에 들어오는 배
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cycle[5001];
int main(void)
{
	freopen("s_input4371.txt", "r", stdin);
	int T, N, D;
	register int tc, n, c, r, ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		ret = 1;
		scanf("%d", &N);
		for (n = 0; n < N; ++n)
		{
			scanf("%d", &D);
			if (D > 1)
			{
				c = (D - 1) / n; r = (D - 1) % n;
				if (!r)
				{
					if (!cycle[c])
					{
						cycle[c] = 1;
						ret++;
					}
				}
			}
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}