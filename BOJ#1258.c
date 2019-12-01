//
//	OS Windows
//	2019.11.26
//
//	[Algorithm Problem Solving]
//
//	[브루트포스]	<BOJ #1258>	문제 할당
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 101
int arr[SZ][SZ];
int check[SZ];
int N, ret;
void recur(int cnt, int sum)
{
	if (sum > ret) return;
	if (cnt == N)
	{
		if (ret > sum) ret = sum;
		return;
	}
	for (register int i = 0; i < N; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			recur(cnt + 1, sum + arr[cnt][i]);
			check[i] = 0;
		}
	}
}
int main(void)
{
	freopen("input1258.txt", "r", stdin);
	ret = 2147000000;
	(void)memset(check, 0, sizeof(check));
	register int r, c;
	scanf("%d", &N);
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			scanf("%d", &arr[r][c]);
		}
	}
	recur(0, 0);
	printf("%d", ret);
	return 0;
}