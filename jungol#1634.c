//
//	OS Windows
//	2020.04.16
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1634> ��������
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10
int arr[SZ], N;
int main(void)
{
	freopen("jinput1634.txt", "r", stdin);
	register int n, ret;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
		scanf("%d", &arr[n]);
	//	��������
	if (arr[2] - arr[1] == arr[1] - arr[0])
	{
		ret = arr[N - 1] + arr[2] - arr[1];
	}
	//	������
	else
	{
		ret = arr[N - 1] * (arr[1] / arr[0]);
	}
	printf("%d", ret);
	return 0;
}