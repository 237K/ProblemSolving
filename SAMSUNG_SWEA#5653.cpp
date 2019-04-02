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

const static int MAP_SIZE = 310;
const static int DIRECT = 4;
const static int COSMOLOGICAL_CONSTANT = 237;

static int N, M, K;
static int org_map[MAP_SIZE * 2 + 51][MAP_SIZE * 2 + 51];
static int life_map[MAP_SIZE * 2 + 51][MAP_SIZE * 2 + 51];
static int dead_map[MAP_SIZE * 2 + 51][MAP_SIZE * 2 + 51];
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static priority_queue<cell> PQ;
static queue<cell> Q;

inline void Print()
{
	for (register int r = 300; r < MAP_SIZE + 50; ++r)
	{
		for (register int c = 300; c < MAP_SIZE + 50; ++c)
		{
			cout << org_map[r][c] << ' ';
		}
		cout << "\n\n";
	}
}

inline int Count()
{
	int all_cell = 0;
	int live_cell = 0;
	int dead_cell = 0;
	for (register int r = 0; r < MAP_SIZE * 2 + 51; ++r)
	{
		for (register int c = 0; c < MAP_SIZE * 2 + 51; ++c)
		{
			if (life_map[r][c] > (COSMOLOGICAL_CONSTANT - 10))
				live_cell++;
			if (org_map[r][c] > 0)
				all_cell++;
			if (life_map[r][c] < 0)
				dead_cell++;
		}
	}
	return all_cell - dead_cell;
}

inline void tiktok()
{
	int dead_cell = 0;
	for (register int r = 0; r < MAP_SIZE * 2 + 51; ++r)
	{
		for (register int c = 0; c < MAP_SIZE * 2 + 51; ++c)
		{
			if (life_map[r][c] > 0)
			{
				life_map[r][c]--;
				if (life_map[r][c] == COSMOLOGICAL_CONSTANT)
				{
					PQ.push({ {r, c}, org_map[r][c] });
				}
				if (life_map[r][c] == dead_map[r][c])
				{
					life_map[r][c] = -(COSMOLOGICAL_CONSTANT);
					dead_cell++;
				}
				
			}
		}
	}
}

inline void rise()
{
	while (!PQ.empty())
	{ 
		Q.push(PQ.top());
		PQ.pop();
	}
	while (!Q.empty())
	{
		cell cur_cell = Q.front();
		Q.pop();
		for (register int d = 0; d < DIRECT; ++d)
		{
			int x = cur_cell.first.first + dir[d][0];
			int y = cur_cell.first.second + dir[d][1];
			int life = cur_cell.second;

			if (org_map[x][y])
				continue;
			else if (!org_map[x][y])
			{
				org_map[x][y] = life;
				life_map[x][y] = life + COSMOLOGICAL_CONSTANT + 1;
				dead_map[x][y] = COSMOLOGICAL_CONSTANT - (life * 2);
			}
		}
	}
}

inline int Execution()
{
	int answer = 0;
	while (K--)
	{
		rise();
		answer = Count();
		tiktok();
	}
	Print();
	return Count();
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
		(void)memset(org_map, 0, sizeof(org_map));
		(void)memset(life_map, 0, sizeof(life_map));
		(void)memset(dead_map, 0, sizeof(dead_map));
		cin >> N >> M >> K;
		for (register int r = MAP_SIZE; r < MAP_SIZE + N; ++r)
		{
			for (register int c = MAP_SIZE; c < MAP_SIZE + M; ++c)
			{
				cin >> org_map[r][c];
				if (org_map[r][c])
				{
					life_map[r][c] = org_map[r][c] + COSMOLOGICAL_CONSTANT;
					dead_map[r][c] = COSMOLOGICAL_CONSTANT - (org_map[r][c] * 2);
				}
			}
		}
		cout << "#" << test_case << ' ' << Execution()<<'\n';
	}
	return 0;
}