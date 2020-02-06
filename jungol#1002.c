//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1002> 최대공약수, 최소공배수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
int arr[MAX], N, low, high, gcd, cm, cur;
int main(void)
{
	freopen("jinput1002.txt", "r", stdin);
	low = 10001; high = 0;
	register int i, j, flag;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		if (low > arr[i]) low = arr[i];
		if (high < arr[i]) high = arr[i];
	}
	for (i = low; i >= 1; --i)
	{
		flag = 1;
		for (j = 0; j < N; ++j)
		{
			if (arr[j] % i)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			gcd = i;
			break;
		}
	}
	i = 0;
	while (1)
	{
		i++;
		cur = high * i;
		flag = 1;
		for (j = 0; j < N; ++j)
		{
			if (cur % arr[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cm = cur;
			break;
		}
	}
	printf("%d %d", gcd, cm);
	return 0;
}