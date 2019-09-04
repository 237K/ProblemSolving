//
//	OS Windows
//	2019.09.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2071] (D1) 평균값 구하기
//

#include <stdio.h>
int main(void)
{
	int T, tc, n, N, acc, ret, rmd;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		acc = ret = 0;
		for (n = 0; n < 10; ++n)
		{
			scanf("%d", &N);
			acc += N;
		}
		ret = acc / 10;
		rmd = acc % 10;
		if (rmd >= 5) ret++;
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}