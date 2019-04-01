//
//	OS Windows
//	2019.04.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5653] <줄기세포배양> (모의 SW 역량테스트)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> coor;
typedef pair<coor, int> cell;

const static int MAP_SIZE = 650;
const static int TIME = 300;
const static int DIRECT = 4;
const static int COSMOLOGICAL_CONSTATNT = 237;
const static int DEATH_CONSTANT = -237;

static int N, M, K;
static int map[MAP_SIZE][MAP_SIZE];
static int death[MAP_SIZE][MAP_SIZE];
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static queue<cell> Q;

inline void Print()
{
	for (int r = 150; r < 450; ++r)
	{
		for (int c = 150; c < 450; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
}

inline void tiktok()
{
	for (int r = 0; r < MAP_SIZE; ++r)
	{
		for (int c = 0; c < MAP_SIZE; ++c)
		{
			if (map[r][c] > 0)
			{
				map[r][c]--;
				if (map[r][c] == COSMOLOGICAL_CONSTATNT)
				{
					Q.push({ {r, c}, map[r][c] + 1 });
				}
				if (map[r][c] == death[r][c])
				{
					map[r][c] = DEATH_CONSTANT;
				}
			}
		}
	}
}

inline void rise()
{
	while (!Q.empty())
	{
		cell cur_cell = Q.front();
		Q.pop();
		for (int d = 0; d < DIRECT; ++d)
		{
			int x = cur_cell.first.first + dir[d][0];
			int y = cur_cell.first.second + dir[d][1];
			int energy = cur_cell.second;
			int life = energy - COSMOLOGICAL_CONSTATNT;

			if (!map[x][y])
			{
				map[x][y] = energy;
				death[x][y] = energy - (life * 2);
			}
		}
	}
}

inline int check()
{
	int live_cell = 0;
	int death_cell = 0;
	for (int r = 0; r < MAP_SIZE; ++r)
	{
		for (int c = 0; c < MAP_SIZE; ++c)
		{
			if (map[r][c] > 0)
				live_cell++;
			if (map[r][c] == DEATH_CONSTANT)
				death_cell++;
		}
	}
	return live_cell;
}

inline int Execution()
{
	while (K)
	{
		tiktok();
		rise();
		K--;
	}
	return check();
}

int main(int argc, char** argv)
{
	freopen("s_input5653.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		(void)memset(death, 0, sizeof(death));
		cin >> N >> M >> K;
		for (int r = 300; r < 300 + N; ++r)
		{
			for (int c = 300; c < 300 + M; ++c)
			{
				cin >> map[r][c];
				if (map[r][c])
				{
					int life = map[r][c];
					map[r][c] += COSMOLOGICAL_CONSTATNT;
					death[r][c] = map[r][c] - (life * 2);
				}
			}
		}
		cout << "#" << test_case << ' ' << Execution() << '\n';
	}
	return 0;
}