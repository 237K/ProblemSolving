//
//	OS Windows
//	2019.08.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1026	º¸¹°
//
//	ver.2
//

#include <stdio.h>
#include <memory.h>
int N, ret;
int A[50], B[50], comb[50], check[50];
void recur(int cnt)
{
	if (cnt == N)
	{
		register int i, tmp = 0;
		for (i = 0; i < N; ++i)
			tmp += A[comb[i]] * B[i];
		if (ret > tmp) ret = tmp;
		return;
	}
	for (register int c = 0; c < N; ++c)
	{
		if (!check[c])
		{
			check[c] = 1;
			comb[cnt] = c;
			recur(cnt + 1);
			check[c] = 0;
		}
	}
}
int main(void)
{
	freopen("input1026.txt", "r", stdin);
	register int n;
	ret = 2147000000;
	scanf("%d", &N);
	for (n = 0; n < N; ++n) scanf("%d", &A[n]);
	for (n = 0; n < N; ++n) scanf("%d", &B[n]);
	(void)memset(check, 0, sizeof(check));
	recur(0);
	printf("%d", ret);
	return 0;
}