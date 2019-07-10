//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1209] (D3) sum
//

#include <stdio.h>
#define SZ 100
int map[SZ][SZ];
int main(void)
{
	int T, N, M;
	register int tc, r, c, rsum, csum, rdsum, ldsum, ret;
	for (tc = 1; tc <= 10; ++tc)
	{
		scanf("%d", &T);
		rsum = csum = rdsum = ldsum = ret = 0;
		for(r = 0 ; r < SZ ; ++r)
			for(c = 0 ; c < SZ ; ++c)
				scanf("%d", &map[r][c]);

		for (c = 0; c < SZ; ++c)
		{
			rsum = 0;
			for (r = 0; r < SZ; ++r)
			{
				rsum += map[r][c];
			}
			if (ret < rsum) ret = rsum;
		}

		for (r = 0; r < SZ; ++r)
		{
			csum = 0;
			for (c = 0; c < SZ; ++c)
			{
				if (r == c) rdsum += map[r][c];
				if (r + c == 99) ldsum += map[r][c];
				csum += map[r][c];
			}
			if (ret < csum) ret = csum;
		}
		if (ret < rdsum) ret = rdsum;
		if (ret < ldsum) ret = ldsum;
		printf("#%d %d\n", T, ret);
	}
	return 0;
}