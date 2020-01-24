//
//	OS Windows
//	2019.12.23
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç]	<BOJ #1988>	³·Àá½Ã°£
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 3001
int table[MAX], sel[MAX];
int N, B, ret;
int cal()
{
	register int i, sum = 0;
	for (i = 1; i < B; ++i)
	{
		if (sel[i] - sel[i - 1] == 1)
		{
			sum += table[sel[i]];
		}
	}
	return sum;
}
void simul(int cnt, int idx)
{
	if (cnt == B)
	{
		int cur = cal();
		if (ret < cur) ret = cur;
		return;
	}
	for (register int i = idx; i < N; ++i)
	{
		sel[cnt] = i;
		simul(cnt + 1, i + 1);
	}
}
int main(void)
{
	freopen("input1988.txt", "r", stdin);
	scanf("%d %d", &N, &B);
	register int n;
	ret = 0;
	for (n = 0; n < N; ++n) scanf("%d", &table[n]);
	simul(0, 0);
	printf("%d", ret);
	return 0;
}