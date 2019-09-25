//
//	OS Windows
//	2019.09.21
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1110 더하기 사이클
//

#include <stdio.h>
int main(void)
{
	freopen("input1110.txt", "r", stdin);
	int N, n, a, b, cycle = 0;
	scanf("%d", &N);
	n = N;
	while (1)
	{
		cycle++;
		a = n / 10;
		b = n % 10;
		n = a + b;
		n %= 10;
		n += b * 10;
		if (N == n) break;
	}
	printf("%d", cycle);
	return 0;
}