//
//	OS Windows
//	2019.11.25
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <BOJ #1115>	순열
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 51
int A[SZ], B[SZ], P[SZ], isPerfect[SZ], check[SZ];
int N, ret;
int diff()
{
	register int i, cnt = 0;
	for (i = 0; i < N; ++i)
	{
		if (A[i] != P[i]) cnt++;
	}
	return cnt;
}
int makeB()
{
	register int i, cur;
	(void)memset(isPerfect, 0, sizeof(isPerfect));
	B[0] = 0;
	isPerfect[0] = 1;
	for (i = 1; i < N; ++i)
	{
		cur = A[B[i - 1]];
		if (isPerfect[cur]) return 0;
		B[i] = cur;
		isPerfect[cur] = 1;
	}
	return 1;
}
void comb(int cnt)
{
	if (!ret) return;
	if (cnt == N)
	{
		if (makeB())
		{
			int cur = diff();
			if (ret > cur) ret = cur;
		}
		return;
	}
	for (register int i = 0; i < N; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			A[cnt] = i;
			comb(cnt + 1);
			check[i] = 0;
		}
	}
}
int main(void)
{
	freopen("input1115.txt", "r", stdin);
	ret = 55;
	(void)memset(check, 0, sizeof(check));
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; ++i) scanf("%d", &P[i]);
	comb(0);
	printf("%d", ret);
	return 0;
}