//
//	OS Windows
//	2020.03.24
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1404> 자기복제
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cal(int n)
{
	register int i = 1;
	while (n)
	{
		i *= 10;
		n /= 10;
	}
	return i;
}
int main(void)
{
	freopen("jinput1404.txt", "r", stdin);
	int N, NN;
	scanf("%d", &N);
	NN = N * N;
	if ((NN % cal(N)) == N) printf("YES");
	else printf("NO");
	return 0;
}