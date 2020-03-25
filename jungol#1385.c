//
//	OS Windows
//	2020.03.24
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1385> 코스튬 파티
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20001
int cow[MAX], N, S, ret;
void simul(int cnt, int idx, int sum)
{
	if (cnt == 2)
	{
		if (sum <= S)
			ret++;
		return;
	}
	for (register int i = idx; i < N; ++i)
	{
		simul(cnt + 1, i + 1, sum + cow[i]);
	}
}
int main(void)
{
	freopen("jinput1385.txt", "r", stdin);
	register int n;
	ret = 0;
	scanf("%d %d", &N, &S);
	for (n = 0; n < N; ++n)
		scanf("%d", &cow[n]);
	simul(0, 0, 0);
	printf("%d", ret);
	return 0;
}