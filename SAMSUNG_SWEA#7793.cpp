//
//	OS Windows
//	2019.06.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7793] (D5) 오! 나의 여신님
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> coor;
const static int SZ = 50;
const static int DIR = 4;

static int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SZ][SZ];
static int N, M;
static queue<coor> Q_SY;
static queue<coor> Q_devil;
static int route_check[SZ][SZ];
void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cout << map[r][c] << "     ";
		}
		cout << "\n\n";
	}
	cout << '\n';
}
bool outofrange(int r, int c)
{
	if (r < 0 || c < 0 || r >= N || c >= M || map[r][c] == -2)
		return true;
	return false;
}
void devil_action(int t)
{
	int size = Q_devil.size();
	while (size--)
	{
		coor cur = Q_devil.front();
		Q_devil.pop();
		for (register int d = 0; d < DIR; ++d)
		{
			int nr = cur.first + dir[d][0];
			int nc = cur.second + dir[d][1];
			if (outofrange(nr, nc) || map[nr][nc] == -1004 || map[nr][nc] > 0) continue;
			Q_devil.push({ nr, nc });
			map[nr][nc] = t;
		}
	}
}
int simul()
{
	print();
	int time = 0;
	while (!Q_devil.empty())
	{
		devil_action(++time);
	}
	time = 0;
	print();
	while (!Q_SY.empty())
	{
		time++;
		int size = Q_SY.size();
		while (size--)
		{
			coor cur = Q_SY.front();
			Q_SY.pop();
			cout << "cur location (" << cur.first << ", " << cur.second << ")  time : " << time << "\n";
			for (register int d = 0; d < DIR; ++d)
			{
				int nr = cur.first + dir[d][0];
				int nc = cur.second + dir[d][1];
				if (outofrange(nr, nc)) continue;
				if (map[nr][nc] == -1004) return time;
				if (map[nr][nc] != 0 && map[nr][nc] <= time) continue;
				if (route_check[nr][nc]) continue;
				route_check[nr][nc] = 1;
				Q_SY.push({ nr, nc });
			}
		}
	}
	return 0;
}
int main(int argc, char** argv)
{
	freopen("s_input7793.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, ret;
	register int tc, n, m;
	char input;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		while (!Q_devil.empty()) { Q_devil.pop(); }
		while (!Q_SY.empty()) { Q_SY.pop(); }
		(void)memset(route_check, 0, sizeof(route_check));
		cin >> N >> M;
		for (n = 0; n < N; ++n)
		{
			for (m = 0; m < M; ++m)
			{
				cin >> input;
				if (input == 'S')
				{
					map[n][m] = 0;
					route_check[n][m] = 1;
					Q_SY.push({ n, m });
				}
				else if (input == '*')
				{
					map[n][m] = 1;
					Q_devil.push({ n, m });
				}
				else if (input == 'D')
					map[n][m] = -1004;
				else if (input == 'X')
					map[n][m] = -2;
				else
					map[n][m] = 0;
			}
		}
		ret = simul();
		if (ret) cout << "#" << tc << ' ' << ret << '\n';
		else cout << "#" << tc << ' ' << "GAME OVER\n";
	}
	return 0;
}