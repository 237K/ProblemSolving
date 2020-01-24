//
//	OS Windows
//	2020.01.02
//
//	[Algorithm Problem Solving]
//
//	[����]	<BOJ #2435>	���û ���� ������
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
int arr[SZ], N, K;
int main(void)
{
	freopen("input2435.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	register int i, j, sum, ret = -2147000000;
	for (i = 0; i < N; ++i) scanf("%d", &arr[i]);
	for (i = 0; i <= N - K; ++i)
	{
		sum = 0;
		for (j = i; j < i + K; ++j)
		{
			sum += arr[j];
		}
		if (ret < sum) ret = sum;
	}
	printf("%d", ret);
	return 0;
}