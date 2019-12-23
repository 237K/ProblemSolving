//
//	OS Windows
//	2019.12.21
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç]	<BOJ #1940>	ÁÖ¸ù
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 150000
#define SEL 2
int table[MAX];
int N, M, ret;
void comb(int cnt, int idx, int sum)
{
	if (cnt == SEL)
	{
		if (sum == M) ret++;
		return;
	}
	for (register int i = idx; i < N; ++i)
	{
		comb(cnt + 1, i + 1, sum + table[i]);
	}
}
int main(void)
{
	freopen("input1940.txt", "r", stdin);
	scanf("%d\n%d", &N, &M);
	ret = 0;
	register int i;
	for (i = 0; i < N; ++i) scanf("%d", &table[i]);
	comb(0, 0, 0);
	printf("%d", ret);
	return 0;
}