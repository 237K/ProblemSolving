//
//	OS Windows
//	2020.05.18
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1900> 1���� n���� Ȧ���� ��
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N, i, sum = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		if (i % 2)
		{
			sum += i;
			printf("%d")
		}
	}
	return 0;
}