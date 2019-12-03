//
//	OS Windows
//	2019.11.29
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #1453>	피시방 알바
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 101
int arr[MAX];
int main(void)
{
	int N, n, i, ret = 0;
	(void)memset(arr, 0, sizeof(arr));
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &i);
		if (arr[i]) ret++;
		else arr[i] = 1;
	}
	printf("%d", ret);
	return 0;
}