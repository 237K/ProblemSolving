//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1045> 암스트롱 수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 3
int dep(int n)
{
	register int N, i, sum = 0;
	N = n;
	while (n)
	{
		i = n % 10;
		n /= 10;
		sum += i * i * i;
	}
	if (sum == N) return 1;
	else return 0;
}
int main(void)
{
	freopen("jinput1045.txt", "r", stdin);
	int i, N;
	scanf("%d", &N);
	if (N < 153) printf("0");
	else
	{
		for (i = 153; i <= N; ++i)
		{
			if (dep(i)) printf("%d\n", i);
		}
	}
	return 0;
}