//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç] <jungol#1504> Blackjack
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
#define SEL 3
int N, M, arr[SZ], ret;
void recur(int cnt, int idx, int sum)
{
	if (cnt == SEL)
	{
		if (sum <= M && ret < sum)
			ret = sum;
		return;
	}
	for (register int i = idx; i < N; ++i)
	{
		recur(cnt + 1, i + 1, sum + arr[i]);
	}
}
int main(void)
{
	freopen("jinput1504.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int n;
	ret = 0;
	for (n = 0; n < N; ++n)
		scanf("%d", &arr[n]);
	recur(0, 0, 0);
	printf("%d", ret);
	return 0;
}