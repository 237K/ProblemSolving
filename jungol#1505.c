//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1505> ���ӵ�
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cal(int a, int t)
{
	register int i, cur = 0, ret = 0;
	for (i = 0; i < t; ++i)
	{
		cur += a;
		ret += cur;
	}
	return ret;
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d", cal(N, M));
	return 0;
}