//
//	OS Windows
//	2020.04.19
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1707> 달팽이사각형
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 101
#define DIR 4
int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int table[SZ][SZ], N;
void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			printf("%d ", table[r][c]);
		}
		printf("\n");
	}
}
int check(int nr, int nc)
{
	if (nr >= N || nc >= N || nr < 0 || nc < 0 || table[nr][nc])
		return 0;
	return 1;
}
void simul()
{
	register int cr = 0, cc = 0, d = 0, nr, nc, cur = 1, flag = 1;
	while (1)
	{
		table[cr][cc] = cur++;
		nr = cr + dir[d][0];
		nc = cc + dir[d][1];
		if (!check(nr, nc))
		{
			d = (d + 1) % 4;
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (!check(nr, nc))
				flag = 0;
		}
		if (!flag) break;
		cr = nr;
		cc = nc;
	}
	print();
}
int main(void)
{
	freopen("jinput1707.txt", "r", stdin);
	(void)memset(table, 0, sizeof(table));
	scanf("%d", &N);
	simul();
	return 0;
}