//
//	OS Windows
//	2020.05.14
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1864> 유일한 수 맞추기 게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 200
#define GAME 3
int table[SZ][GAME], N, score[SZ];
int main(void)
{
	scanf("%d", &N);
	register int r, rr, c, cnt, cur, flag;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < GAME; ++c)
		{
			scanf("%d", &table[r][c]);
		}
	}
	for (r = 0; r < N; ++r)
	{
		cnt = 0;
		for (c = 0; c < GAME; ++c)
		{
			flag = 1;
			cur = table[r][c];
			for (rr = 0; rr < N; ++rr)
			{
				if (r == rr) continue;
				if (cur == table[rr][c])
				{
					flag = 0;
					break;
				}
			}
			if (flag) cnt += cur;
		}
		printf("%d\n", cnt);
	}
	return 0;
}