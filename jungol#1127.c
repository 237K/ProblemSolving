//
//	OS Windows
//	2020.02.11
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1127> 맛있는 음식
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10
int sin[SZ], ssn[SZ], N, ret;
void comb(int cnt, int idx, int sinmat, int ssnmat)
{
	if (cnt > N) return;
	if (cnt > 0)
	{
		int cur = sinmat - ssnmat;
		if (cur < 0) cur *= -1;
		if (ret > cur) ret = cur;
	}
	for (register int i = idx; i < N; ++i)
	{
		comb(cnt + 1, i + 1, sinmat * sin[i], ssnmat + ssn[i]);
	}
}
int main(void)
{
	freopen("jinput1127.txt", "r", stdin);
	ret = 2147000000;
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; ++i)
		scanf("%d %d", &sin[i], &ssn[i]);
	comb(0, 0, 1, 0);
	printf("%d", ret);
	return 0;
}