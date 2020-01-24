//
//	OS Windows
//	2019.11.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1773	ÆøÁ×¼î
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 100
#define TIME 2000001
int arr[TIME];
int N, C, t;
int main(void)
{
	freopen("input1773.txt", "r", stdin);
	scanf("%d %d", &N, &C);
	register int i, n, ret = 0;
	(void)memset(arr, 0, sizeof(arr));
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &t);
		i = 0;
		while (1)
		{
			i += t;
			if (i > C) break;
			if (!arr[i])
			{
				ret++;
				arr[i] = 1;
			}
		}
	}
	printf("%d", ret);
	return 0;
}