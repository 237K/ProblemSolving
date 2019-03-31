//
//	OS Windows
//	2019.03.30
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14502	¿¬±¸¼Ò
//	ver2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;

const static int ROW_SIZE = 8;
const static int COL_SIZE = 8;
const static int WALL = 3;
const static int DIRECT = 4;
const static int INF = -2147000000;

static int map[ROW_SIZE][COL_SIZE];
static int map_cpy[ROW_SIZE][COL_SIZE];
bool check_wall[ROW_SIZE*COL_SIZE];
static vector<coor> virus;
static queue<coor> Q;
static vector<coor> space;
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static int N, M;
static int Result = INF;

inline void Print()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
}

inline void ClearMap()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if (map[r][c] == 3)
				map[r][c] = 0;
		}
	}
}

inline int Count()
{
	int count = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if (!map[r][c])
				count++;
		}
	}
	return count;
}

inline void Diff()
{
	for (vector<coor>::size_type i = 0; i < virus.size(); ++i)
		Q.push(coor(virus[i].first, virus[i].second));

	while(!Q.empty())
	{
		coor cur = Q.front();
		Q.pop();
		for (int d = 0; d < DIRECT; ++d)
		{
			int x = cur.first + dir[d][0];
			int y = cur.second + dir[d][1];
			if (x < 0 || y < 0 || x >= N || y >= M || map[x][y])
				continue;
			else
			{
				map[x][y] = 3;
				Q.push(coor(x, y));
			}
		}
	}
}

inline void Simulation(int wall)
{
	if (wall == WALL)
	{
		Diff();
		int safety_zone = Count();
		Result = max(Result, safety_zone);

		ClearMap();

		return;
	}
	
	else
	{
		for (vector<coor>::size_type i = 0; i < space.size(); ++i)
		{
			if (!check_wall[i])
			{
				check_wall[i] = true;
				int x = space[i].first;
				int y = space[i].second;
				map[x][y] = 1;
				Simulation(wall + 1);
				map[x][y] = 0;
				check_wall[i] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input14502.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	(void)memset(map, 0, sizeof(map));
	(void)memset(map_cpy, 0, sizeof(map_cpy));

	cin >> N >> M;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			map_cpy[r][c] = map[r][c];
			if (!map[r][c])
			{
				space.push_back(coor(r, c));
			}
			if (map[r][c] == 2)
			{
				virus.push_back(coor(r, c));
			}
		}
	}
	Simulation(0);
	cout << Result;
	return 0;
}