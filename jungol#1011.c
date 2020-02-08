//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1011> 소수 369
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 1000
int arr[MAX], N, M, K, i, j;
int check_prime(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	register int i, flag = 1;
	for (i = 2; i < n; ++i)
	{
		if (!(n % i))
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int main(void)
{
	freopen("jinput1011.txt", "r", stdin);
	(void)memset(arr, 0, sizeof(arr));
	scanf("%d %d %d", &N, &M, &K);
	j = 0;
	for (i = 1; i <= M; ++i)
	{
		if (check_prime(i))
			arr[j]++;
		j = (j + 1) % N;
	}
	printf("%d", arr[K]);
	return 0;
}