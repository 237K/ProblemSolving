//
//	OS Windows
//	2020.07.11
//
//	[Algorithm Problem Solving]
//
//	[����] <BOJ #5522> ī�� ����
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int main(void)
{
	int i, n, sum = 0;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &n);
		sum += n;
	}
	printf("%d", sum);
	return 0;
}