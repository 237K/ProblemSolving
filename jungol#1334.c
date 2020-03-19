//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1334> 대표값
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define T 10
#define SZ 1001
int arr[SZ];
int main(void)
{
	freopen("jinput1334.txt", "r", stdin);
	int tc, n, sum = 0, cnt = 0, fre;
	(void)memset(arr, 0, sizeof(arr));
	for (tc = 0; tc < T; ++tc)
	{
		scanf("%d", &n);
		sum += n;
		if ((++arr[n]) > cnt)
		{
			cnt = arr[n];
			fre = n;
		}
	}
	printf("%d\n%d", sum / T, fre);
	return 0;
}