//
//	OS Windows
//	2019.12.10
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #1568>	새
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int simul(int n)
{
	register int cnt = 0, tik = 0;
	while (1)
	{
		if (!n) break;
		cnt++; tik++;
		if (n < cnt) cnt = 1;
		n -= cnt;
	}
	return tik;
}
int main(void)
{
	freopen("input1568.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	printf("%d", simul(N));
	return 0;
}