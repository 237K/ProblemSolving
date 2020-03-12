//
//	OS Windows
//	2020.03.04
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1236> uniqueness2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 10001
int arr[MAX], N;
int main(void)
{
	freopen("jinput1236.txt", "r", stdin);
	int n, in, cnt = 0;
	(void)memset(arr, 0, sizeof(arr));
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &in);
		if (arr[in]) continue;
		arr[in]++;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}