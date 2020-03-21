//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1353> 두 수의 합2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 15000
int arr[SZ], N, M, ret;
void comb(int cnt, int idx, int sum)
{
	if (cnt == 2)
	{
		if (sum == M)
			ret++;
		return;
	}
	for (register int i = idx; i < N; ++i)
		comb(cnt + 1, i + 1, sum + arr[i]);
}
int main(void)
{
	freopen("jinput1353.txt", "r", stdin);
	ret = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	for (register int i = 0; i < M; ++i)
		scanf("%d", &arr[i]);
	comb(0, 0, 0);
	printf("%d", ret);
	return 0;
}