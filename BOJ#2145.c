//
//	OS Windows
//	2019.12.26
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2145>	숫자 놀이
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cal(int n)
{
	register int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main(void)
{
	freopen("input2145.txt", "r", stdin);
	int N;
	while (1)
	{
		scanf("%d", &N);
		if (!N) break;
		while (1)
		{
			if (!(N / 10)) break;
			N = cal(N);
		}
		printf("%d\n", N);
	}
	return 0;
}