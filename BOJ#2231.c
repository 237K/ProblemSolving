//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2231 ºÐÇØÇÕ
//

#include <stdio.h>
int N;
int cal(int n)
{
	register int acc;
	acc = n;
	while (n)
	{
		acc += n % 10;
		n /= 10;
	}
	return acc;
}
int simul()
{
	register int i;
	for (i = 1; i < N; ++i)
	{
		if (N == cal(i)) return i;
	}
	return 0;
}
int main(void)
{
	freopen("input2231.txt", "r", stdin);
	scanf("%d", &N);
	printf("%d", simul());
	return 0;
}