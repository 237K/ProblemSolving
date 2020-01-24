//
//	OS Windows
//	2020.01.06
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2592>	대표값
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 1001
#define MAX 10
int arr[SZ];
int main(void)
{
	freopen("input2592.txt", "r", stdin);
	(void)memset(arr, 0, sizeof(arr));
	int i, cur, sum = 0, avg, m = 0, ret;
	for (i = 0; i < MAX; ++i)
	{
		scanf("%d", &cur);
		sum += cur;
		arr[cur]++;
		if (arr[cur] > m)
		{
			m = arr[cur];
			ret = cur;
		}
	}
	avg = sum / MAX;
	printf("%d\n%d", avg, ret);
	return 0;
}