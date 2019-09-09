//
//	OS Windows
//	2019.09.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2068] (D1) 최대수 구하기
//

#include <stdio.h>
#define T 3
#define N 10
int main(void)
{
	int tc, n, in, ret;
	for (tc = 1; tc <= T; ++tc)
	{
		ret = 0;
		for (n = 0; n < N; ++n)
		{
			scanf("%d", &in);
			if (ret < in) ret = in;
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}