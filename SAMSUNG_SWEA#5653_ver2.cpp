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

static int N, M, K;
static int map[MAP_SIZE * 2 + 51][MAP_SIZE * 2 + 51];
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static priority_queue<cell> PQ;
static queue<cell> Q;

inline int tiktok()
{
	int sleep = 0;
	int wakeup = 0;

	while (!PQ.empty())
	{
		Q.push(PQ.top());
		PQ.pop();
	}
	while (K--)
	{
		int tik = Q.size();
		while (tik--)
		{
			cell cur_cell = Q.front();
			Q.pop();
			int life = cur_cell.second;
			int dead = -(cur_cell.second);

			if (life-- == 0)
			{
				if (cur_cell.second - 1 > K)
					sleep++;
				for (register int d = 0; d < DIRECT; ++d)
				{
					int x = cur_cell.first.first + dir[d][0];
					int y = cur_cell.first.second + dir[d][1];

					if (map[x][y])
						continue;
					else if (!map[x][y])
					{
						map[x][y] = cur_cell.second;
						Q.push({ {x, y}, map[x][y] });
					}
				}
			}
			else
				Q.push({ {cur_cell.first.first, cur_cell.first.second}, life });
		}
	}
	wakeup = Q.size();
	return sleep + wakeup;
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
		cin >> N >> M >> K;
		for (register int r = MAP_SIZE; r < MAP_SIZE + N; ++r)
		{
			for (register int c = MAP_SIZE; c < MAP_SIZE + M; ++c)
			{
				cin >> map[r][c];
				if (map[r][c])
					PQ.push({ {r, c}, map[r][c] });
			}
		}
		cout << "#" << test_case << ' ' << tiktok() << '\n';
	}
	return 0;
}