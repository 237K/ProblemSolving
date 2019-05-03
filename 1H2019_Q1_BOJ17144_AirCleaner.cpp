//
//	OS Windows
//	2019.04.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17144	공기청정기 (2019상반기 1번 문제)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> coor;
const static int DIRECT = 4;
const static int SIZE = 51;

static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int R, C, T;
static int map[SIZE][SIZE];
static int dust_map[SIZE][SIZE];
static coor upper_cleaner;
static coor lower_cleaner;
static vector<coor> dust;

inline void spread()
{
	int num_dust_start = dust.size();
	for (register int dst = 0; dst < num_dust_start; ++dst)
	{
		int spread_dust = 0;
		int cr = dust[dst].first;
		int cc = dust[dst].second;
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nr = cr + dir[d][0];
			int nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc] < 0)
				continue;
			else
			{
				dust_map[nr][nc] += map[cr][cc] / 5;
				spread_dust += map[cr][cc] / 5;
			}
		}
		dust_map[cr][cc] -= spread_dust;
	}
	for (register int r = 0; r < R; ++r)
	{
		for (register int c = 0; c < C; ++c)
		{
			if (map[r][c] != -1)
				map[r][c] += dust_map[r][c];
		}
	}
	(void)memset(dust_map, 0, sizeof(dust_map));
}
inline void clean()
{
	int temp1 = 0, temp2 = 0;
	//	right shift
	temp1 = map[upper_cleaner.first][C - 1];
	temp2 = map[lower_cleaner.first][C - 1];
	for (register int c = C - 1; c > upper_cleaner.second+1; --c)
	{
		map[upper_cleaner.first][c] = map[upper_cleaner.first][c - 1];
		map[lower_cleaner.first][c] = map[lower_cleaner.first][c - 1];
	}
	map[upper_cleaner.first][upper_cleaner.second + 1] = 0;
	map[lower_cleaner.first][lower_cleaner.second + 1] = 0;

	int temp3 = 0, temp4 = 0;
	//	up shift
	temp3 = map[0][C - 1];
	for (register int r = 0; r < upper_cleaner.first; ++r)
		map[r][C-1] = map[r + 1][C-1];
	map[upper_cleaner.first - 1][C - 1] = temp1;

	//	down shift
	temp4 = map[R - 1][C - 1];
	for (register int r = R - 1; r > lower_cleaner.first; --r)
		map[r][C - 1] = map[r - 1][C - 1];
	map[lower_cleaner.first + 1][C - 1] = temp2;

	int temp5 = 0, temp6 = 0;
	//	left shift
	temp5 = map[0][0];
	temp6 = map[R - 1][0];
	for (register int c = 0; c < C-1; ++c)
	{
		map[0][c] = map[0][c + 1];
		map[R - 1][c] = map[R - 1][c + 1];
	}
	map[0][C - 2] = temp3;
	map[R - 1][C - 2] = temp4;

	//	to upper_cleaner
	for (register int r = upper_cleaner.first - 1; r > 0; --r)
		map[r][0] = map[r - 1][0];
	map[1][0] = temp5;

	//	to lower_cleaner
	for (register int r = lower_cleaner.first + 1; r < R - 1; ++r)
		map[r][0] = map[r + 1][0];
	map[R - 2][0] = temp6;
	
	dust.clear();
	for (register int r = 0; r < R; ++r)
	{
		for (register int c = 0; c < C; ++c)
		{
			if (map[r][c] > 0)
				dust.push_back({ r, c });
		}
	}
}
inline int count()
{
	int cnt = 0;
	for (register int r = 0; r < R; ++r)
	{
		for (register int c = 0; c < C; ++c)
		{
			if (map[r][c] > 0)
				cnt += map[r][c];
		}
	}
	return cnt;
}
inline int simulation()
{
	while (T)
	{
		T--;
		spread();
		clean();
	}
	return count();
}
int main(int argc, char** argv)
{
	freopen("input17144.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cleaner_flag = 0;
	cin >> R >> C >> T;
	for (register int r = 0; r < R; ++r)
	{
		for (register int c = 0; c < C; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == -1 && !cleaner_flag)
			{
				upper_cleaner = { r, c };
				cleaner_flag = 1;
			}
			else if (map[r][c] == -1 && cleaner_flag)
				lower_cleaner = { r, c };
			else if (map[r][c] > 0)
			{
				dust.push_back({ r, c });
			}
		}
	}
	cout << simulation() << '\n';
	return 0;
}