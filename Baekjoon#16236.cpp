//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16236	아기상어
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> coor;
typedef pair<coor, int> coor_and_distance;

const static int MAX = 21;
const static int INF = 2147000000;
const static int DIRECT = 4;

struct fish
{
	int x, y, distance;
};

struct shark
{
	int x, y, size, eat;
};

static int map[MAX][MAX];
static bool check[MAX][MAX];
static int map_distance[MAX][MAX];
static int N;
static shark baby_shark;
static queue<coor> Q;
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static int shortest_dist = INF;
static queue<coor_and_distance> CDQ;

inline int cal_dist(int x, int y)
{
	CDQ.push({ {baby_shark.x, baby_shark.y}, 0 });
	check[baby_shark.x][baby_shark.y] = true;
	while (!CDQ.empty())
	{
		coor_and_distance cur = CDQ.front();
		CDQ.pop();
		int xx = cur.first.first;
		int yy = cur.first.second;
		int dd = cur.second;
		if (xx == x && yy == y)
		{
			while (!CDQ.empty()) { CDQ.pop(); }
			return dd;
		}

		for (register int d = 0; d < DIRECT; ++d)
		{
			int nx = xx + dir[d][0];
			int ny = yy + dir[d][0];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || check[nx][ny] || map[nx][ny] > baby_shark.size)
				continue;
			else
			{
				check[nx][ny] = true;
				CDQ.push({ {nx, ny}, d + 1 });
			}
		}
	}
}

inline fish find_fish()
{
	fish f = { INF, INF, INF };

	int Qsize = Q.size();
	if (!Qsize) return f;
	else
	{
		while (Qsize--)
		{
			coor cur_fish = Q.front();
			Q.pop();

			if (map[cur_fish.first][cur_fish.second] < baby_shark.size)
			{
				(void)memset(check, false, sizeof(check));
				(void)memset(map_distance, 0, sizeof(map_distance));
				//shortest_dist = INF;
				//cal_dist(cur_fish.first, cur_fish.second);
				int cur_fish_dist = cal_dist(cur_fish.first, cur_fish.second);
				if (f.distance > cur_fish_dist)
				{
					if (f.x != INF && f.y != INF)
						Q.push({ f.x, f.y });
					f.x = cur_fish.first;
					f.y = cur_fish.second;
					f.distance = cur_fish_dist;
				}
				else if (f.distance == cur_fish_dist)
				{
					if (f.x > cur_fish.first || (f.x == cur_fish.first && f.y > cur_fish.second))
					{
						if (f.x != INF && f.y != INF)
							Q.push({ f.x, f.y });
						f.x = cur_fish.first;
						f.y = cur_fish.second;
					}
					else
						Q.push({ cur_fish.first, cur_fish.second });
				}
				else
					Q.push({ cur_fish.first, cur_fish.second });
			}
			else
				Q.push({ cur_fish.first, cur_fish.second });
			
		}
	}
	return f;
}

inline int move_and_eat(int cnt)
{
	fish cur_fish = find_fish();
	if (cur_fish.x == INF)
	{
		return cnt;
	}
	else
	{
		baby_shark.x = cur_fish.x;
		baby_shark.y = cur_fish.y;
		if (++baby_shark.eat == baby_shark.size)
		{
			baby_shark.size++;
			baby_shark.eat = 0;
		}
		map[cur_fish.x][cur_fish.y] = 0;
		move_and_eat(cnt + cur_fish.distance);
	}
}

int main(int argc, char** argv)
{
	freopen("s_input16236.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, false, sizeof(check));
	cin >> N;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 9)
			{
				baby_shark.x = r;
				baby_shark.y = c;
				baby_shark.size = 2;
				baby_shark.eat = 0;
				map[r][c] = 0;
			}
			else if (map[r][c] > 0 && map[r][c] <= 6)
			{
				Q.push({ r, c });
			}
		}
	}
	cout << move_and_eat(0);
	return 0;
}