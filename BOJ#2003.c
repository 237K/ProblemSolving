//
//	OS Windows
//	2019.12.23
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2003>	수들의 합 2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000
int arr[MAX], N, M;
int main(void)
{
	freopen("input2003.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int i, j, k, sum, ret = 0;
	for (i = 0; i < N; ++i) scanf("%d", &arr[i]);
	for (i = 0; i < N; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			sum = 0;
			for (k = i; k < j + i; ++k)
			{
				sum += arr[k];
				if (sum > M) break;
			}
			if (sum > M)
				break;
			if (sum == M) ret++;
		}
		
	}
	printf("%d", ret);
	return 0;
}