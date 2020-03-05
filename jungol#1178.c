//
//	OS Windows
//	2020.03.02
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1178> ������ ���� �ڸ���
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count(int n)
{
	register int cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}
int main(void)
{
	int T, tc, A, B;
	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &A, &B);
		printf("%d %d\n", A * B, count(A * B));
	}
	return 0;
}