//
//	OS Windows
//	2020.08.23
//
//	[Algorithm Problem Solving]
//
//	SWEA #10505 (D3) ¼Òµæ ºÒ±ÕÇü
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10000
int T, arr[SZ], n, sum, avg, ret;
int main(void)
{
	register int tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		sum = ret = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		avg = sum / n;
		for (i = 0; i < n; ++i)
		{
			if (arr[i] <= avg)
				ret++;
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}