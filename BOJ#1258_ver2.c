//
//	OS Windows
//	2019.11.26
//
//	[Algorithm Problem Solving]
//
//	[브루트포스]	<BOJ #1258>	문제 할당
//
//	ver.2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 100
#define MAX 1001
int arr[SZ][SZ];
int check[SZ];
int N;
int cal()
{
	(void)memset(check, 0, sizeof(check));
	register int r, c, sum = 0, m, midx;
	for (c = 0; c < N; ++c)
	{
		m = MAX;
		for (r = 0; r < N; ++r)
		{
			if (check[r]) continue;
			if (m > arr[r][c])
			{
				m = arr[r][c];
				midx = r;
			}
		}
		check[midx] = 1;
		sum += m;
	}
	return sum;
}
int main(void)
{
	freopen("input1258.txt", "r", stdin);
	scanf("%d", &N);
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			scanf("%d", &arr[r][c]);
		}
	}
	printf("%d", cal());
	return 0;
}