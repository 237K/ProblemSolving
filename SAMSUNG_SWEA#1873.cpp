//
//	OS Windows
//	2019.07.16
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1873] (D3) 상호의 배틀필드
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> TANK;
const static int SZ = 20;
const static int DIR = 4;
static char map[SZ][SZ];
static int T, N, H, W;
static int dir[DIR][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
static string order;
static TANK tank;
static int tank_dir;
inline void init()
{
	register int r, c;
	for (r = 0; r < SZ; ++r)
		for (c = 0; c < SZ; ++c)
			map[r][c] = ' ';
	order.clear();
	tank = { 0, 0 };
	tank_dir = 0;
}
inline void find_tank()
{
	register int r, c;
	bool flag = false;
	for (r = 0; r < H; ++r)
	{
		for (c = 0; c < W; ++c)
		{
			if (map[r][c] == '^' || map[r][c] == 'v' || map[r][c] == '<' || map[r][c] == '>')
			{
				tank = { r, c };
				if (map[r][c] == '^') tank_dir = 0;
				else if (map[r][c] == 'v') tank_dir = 1;
				else if (map[r][c] == '<') tank_dir = 2;
				else tank_dir = 3;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	map[tank.first][tank.second] = '.';
}
inline void print()
{
	if (tank_dir == 0) map[tank.first][tank.second] = '^';
	else if (tank_dir == 1) map[tank.first][tank.second] = 'v';
	else if (tank_dir == 2) map[tank.first][tank.second] = '<';
	else map[tank.first][tank.second] = '>';
	register int r, c;
	for (r = 0; r < H; ++r)
	{
		for (c = 0; c < W; ++c)
		{
			cout << map[r][c];
		}
		cout << '\n';
	}
}
inline void move(int d)
{
	register int nr, nc;
	tank_dir = d;
	nr = tank.first + dir[tank_dir][0];
	nc = tank.second + dir[tank_dir][1];
	if (nr < 0 || nc < 0 || nr >= H || nc >= W || map[nr][nc] == '*' || map[nr][nc] == '#' || map[nr][nc] == '-') return;
	tank.first = nr;
	tank.second = nc;
}
inline void simulation()
{
	find_tank();
	register int i, cr, cc, nr, nc;
	for (i = 0; i < N; ++i)
	{
		if (order[i] == 'U') move(0);
		else if (order[i] == 'D') move(1);
		else if (order[i] == 'L') move(2);
		else if (order[i] == 'R') move(3);
		else
		{
			cr = tank.first;
			cc = tank.second;
			while (1)
			{
				nr = cr + dir[tank_dir][0];
				nc = cc + dir[tank_dir][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc] == '#') break;
				if (map[nr][nc] == '*')
				{
					map[nr][nc] = '.';
					break;
				}
				cr = nr;
				cc = nc;
			}
		}
	}
	print();
}
int main(int argc, char** argv)
{
	freopen("s_input1873.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, r;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		init();
		cin >> H >> W;
		for (r = 0; r < H; ++r) cin >> map[r];
		cin >> N;
		cin >> order;
		cout << "#" << tc << ' ';
		simulation();
	}
	return 0;
}