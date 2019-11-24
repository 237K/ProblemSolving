//
//	OS Windows
//	2019.11.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2846	오르막길
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1001
int arr[SZ];
int N;
int main(void)
{
	freopen("input2846.txt", "r", stdin);
	scanf("%d", &N);
	register int n, diff = 0, ret = 0;
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
		if (n > 0)
		{
			if (arr[n] > arr[n - 1])
			{
				diff += arr[n] - arr[n - 1];
			}
			else
			{
				if (ret < diff) ret = diff;
				diff = 0;
			}
		}
	}
	if (ret < diff) ret = diff;
	printf("%d", ret);
	return 0;
}