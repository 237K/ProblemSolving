//
//	OS Windows
//	2019.08.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1070	±èÁö¹ÎÀÇ Ä§·«
//

#include <stdio.h>
#define DIR 4
int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[51][51];
int cost[26];
int N, M, in, cap_r, cap_c;
int solve()
{
	register int r, c, d, nd1, nd2, a, nr, nc, nnr, nnc, nnr2, nnc2, tmp, ret;
	cap_r = cap_c = ret = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			if (map[r][c] == '*')
			{
				cap_r = r;
				cap_c = c;
				break;
			}
		}
		if (cap_r && cap_c) break;
	}
	for (d = 0; d < 4; ++d)
	{
		a = 1;
		tmp = 1000001;
		while (1)
		{
			nr = cap_r + (a * dir[d][0]);
			nc = cap_c + (a * dir[d][1]);
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
			if (map[nr][nc] == '-')
			{
				tmp = 0;
				break;
			}
			if (tmp > cost[map[nr][nc] - 'A']) tmp = cost[map[nr][nc] - 'A'];
			nd1 = (d + 1) % 4;
			nd2 = (d + 3) % 4;
			nnr = nr + dir[nd1][0]; nnr2 = nr + dir[nd2][0];
			nnc = nc + dir[nd1][1]; nnc2 = nc + dir[nd2][1];
			if (map[nnr][nnc] != '-' || map[nnr2][nnc2] != '-') break;
			a++;
		}
		ret += tmp;
	}
	return ret;
}
int main(void)
{
	freopen("input1070.txt", "r", stdin);
	register int r, c;
	scanf("%d %d", &N, &M);
	for (r = 0; r < N; ++r) scanf("%s", &map[r]);
	for (c = 0; c < 26; ++c)
	{
		scanf("%d", &in);
		cost[c] = in;
	}
	printf("%d", solve());
	return 0;
}