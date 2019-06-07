//
//	OS Windows
//	2019.05.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3055	Å»Ãâ
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> coor;
typedef pair<coor, int> coor_and_time;
const static string MSG_FAIL = "KAKTUS";
const static int SIZE = 50;
const static int DIRECT = 4;

static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static char map[SIZE][SIZE];
static int visit[SIZE][SIZE];
static int R, C;
static queue<coor> water;
static queue<coor_and_time> Q;

inline int simulation()
{
	register int d, w_size, s_size;
	int arrive_flag = 0;
	int ret = 0;
	while (1)
	{
		//	È«¼ö ¹ü¶÷
		w_size = water.size();
		while (w_size--)
		{
			coor cur = water.front();
			water.pop();
			for (d = 0; d < DIRECT; ++d)
			{
				int nr = cur.first + dir[d][0];
				int nc = cur.second + dir[d][1];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc] == 'X' || map[nr][nc] == 'D' || map[nr][nc] == '*')
					continue;
				else
				{
					map[nr][nc] = '*';
					water.push({ nr, nc });
				}
			}
		}

		//	°í½¿µµÄ¡ ÀÌµ¿
		s_size = Q.size();
		if (!s_size) break;

		while (s_size--)
		{
			coor_and_time cur = Q.front();
			Q.pop();
			for (d = 0; d < DIRECT; ++d)
			{
				int nr = cur.first.first + dir[d][0];
				int nc = cur.first.second + dir[d][1];
				int nm = cur.second;
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc] == 'X' || map[nr][nc] == '*' || visit[nr][nc])
					continue;
				else
				{
					if (map[nr][nc] == 'D')
					{
						ret = nm;
						arrive_flag = 1;
						break;
					}
					else
					{
						visit[nr][nc] = 1;
						Q.push({ {nr, nc}, nm + 1 });
					}
				}
			}
			if (arrive_flag) break;
		}
		if (arrive_flag) break;
	}
	while (!water.empty()) water.pop();
	while (!Q.empty()) Q.pop();

	return ret;
}
int main(void)
{
	freopen("input3055.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (!water.empty()) water.pop();
	while (!Q.empty()) Q.pop();
	register int r, c;
	cin >> R >> C;
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == '*')
				water.push({ r, c });
			else if (map[r][c] == 'S')
			{
				Q.push({ {r, c}, 1 });
				visit[r][c] = 1;
			}
		}
	}
	int result = simulation();
	if (!result) cout << MSG_FAIL;
	else cout << result;
	return 0;
}