//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17144	미세먼지 안녕!
//
//	ver.2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 50;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], map_cpy[SZ][SZ];
static pii dust[SZ * SZ];
static int R, C, T;
static pii upper_cleaner, lower_cleaner;
inline void map_init()
{
	register int r, c;
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			map_cpy[r][c] = 0;
}
inline void map_sum()
{
	register int r, c;
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] >= 0)
				map[r][c] += map_cpy[r][c];
		}
	}
}
inline void spread()
{
	register int nr, nc, r, c, d, a, cnt, num_dust = 0, i;
	//	이번에 확산할 먼지 확인
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] > 0)
				dust[num_dust++] = { r, c };
		}
	}
	//	확산
	map_init();
	for (i = 0; i < num_dust; ++i)
	{
		pii cur = dust[i];
		cnt = 0;
		a = map[cur.first][cur.second] / 5;
		for (d = 0; d < DIR; ++d)
		{
			nr = cur.first + dir[d][0];
			nc = cur.second + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc] < 0) continue;
			cnt++;
			map_cpy[nr][nc] += a;
		}
		map_cpy[cur.first][cur.second] -= a * cnt;
	}
	map_sum();
}
inline int right_shift(int r)
{
	register int c, tmp;
	tmp = map[r][C - 1];
	for (c = C - 1; c > 1; --c) map[r][c] = map[r][c - 1];
	map[r][1] = 0;
	return tmp;
}
inline int left_shift(int r, int ac)
{
	register int c, tmp;
	tmp = map[r][0];
	for (c = 0; c < C - 1; ++c) map[r][c] = map[r][c + 1];
	map[r][C - 2] = ac;
	return tmp;
}
inline void operation()
{
	register int upper_ac, lower_ac, r, upper_ac2, lower_ac2, upper_ac3, lower_ac3;
	upper_ac = right_shift(upper_cleaner.first);
	lower_ac = right_shift(lower_cleaner.first);
	//	upper cleaner up cycle
	upper_ac2 = map[0][C - 1];
	for (r = 0; r < upper_cleaner.first; ++r) map[r][C - 1] = map[r + 1][C - 1];
	map[upper_cleaner.first - 1][C - 1] = upper_ac;
	//	upper cleaner left cycle
	upper_ac3 = left_shift(0, upper_ac2);
	//	upper cleaner down cycle
	for (r = upper_cleaner.first - 1; r > 0; --r) map[r][0] = map[r - 1][0];
	map[1][0] = upper_ac3;
	//	lower cleaner down cycle
	lower_ac2 = map[R - 1][C - 1];
	for (r = R - 1; r > lower_cleaner.first; --r) map[r][C - 1] = map[r - 1][C - 1];
	map[lower_cleaner.first + 1][C - 1] = lower_ac;
	//	lower cleaner left cycle
	lower_ac3 = left_shift(R - 1, lower_ac2);
	//	lower cleaner up cycle
	for (r = lower_cleaner.first + 1; r < R - 2; ++r) map[r][0] = map[r + 1][0];
	map[R - 2][0] = lower_ac3;
}
inline int count()
{
	register int r, c, ret = 0;
	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			if (map[r][c] > 0)
				ret += map[r][c];
	return ret;
}
inline int simul()
{
	while (T--)
	{
		spread();
		operation();
	}
	return count();
}
int main(int argc, char** argv)
{
	freopen("input17144.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	upper_cleaner = lower_cleaner = { 0, 0 };
	cin >> R >> C >> T;
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			cin >> map[r][c];
			if (!upper_cleaner.first && map[r][c] == -1)
			{
				upper_cleaner = { r, c };
				lower_cleaner = { r + 1, c };
			}
		}
	}
	cout << simul();
	return 0;
}