//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1009> 각 자리수의 역과 합
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void dep(int n)
{
	int i, rev = 0, sum = 0;
	while (n)
	{
		i = n % 10;
		rev *= 10;
		rev += i;
		sum += i;
		n /= 10;
	}
	printf("%d %d\n", rev, sum);
}
int main(void)
{
	freopen("jinput1009.txt", "r", stdin);
	int N;
	while (1)
	{
		scanf("%d", &N);
		if (!N) break;
		dep(N);
	}
	return 0;
}