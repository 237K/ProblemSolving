//
//	OS Windows
//	2019.12.21
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç]	<BOJ #1996>	Áö·Ú Ã£±â
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1001
#define DIR 8
int dir[DIR][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
					{0, 1}, {1, -1}, {1, 0}, {1, 1} };
char map[SZ][SZ], ret[SZ][SZ];
int N;
void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			printf("%c", ret[r][c]);
		}
		printf("\n");
	}
}
void simul()
{
	register int r, c, nr, nc, d, cnt;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (map[r][c] != '.')
			{
				ret[r][c] = '*';
				continue;
			}
			cnt = 0;
			for (d = 0; d < DIR; ++d)
			{
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if (map[nr][nc] == '.') continue;
				cnt += map[nr][nc] - '0';
			}
			if (cnt > 9) ret[r][c] = 'M';
			else ret[r][c] = cnt + '0';
		}
	}
	print();
}
int main(void)
{
	freopen("input1996.txt", "r", stdin);
	scanf("%d", &N);
	register int r;
	for (r = 0; r < N; ++r)
	{
		scanf("%s", &map[r]);
	}
	simul();
	return 0;
}