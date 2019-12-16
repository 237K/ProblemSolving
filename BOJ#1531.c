//
//	OS Windows
//	2019.12.09
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #1531>	투명
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 101
int map[MAX][MAX];
int ldc, ldr, rtc, rtr, N, M, ret;
int main(void)
{
	freopen("input1531.txt", "r", stdin);
	(void)memset(map, 0, sizeof(map));
	ret = 0;
	scanf("%d %d", &N, &M);
	register int n, r, c;
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d %d %d", &ldc, &ldr, &rtc, &rtr);
		for (r = ldr; r <= rtr; ++r)
		{
			for (c = ldc; c <= rtc; ++c)
			{
				if (map[r][c] < M) map[r][c]++;
				else ret++;
			}
		}
	}
	printf("%d", ret);
	return 0;
}
