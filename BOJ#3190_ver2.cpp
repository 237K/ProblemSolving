//
//	OS Windows
//	2019.05.18
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3190	¹ì
//	ver2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 101;
const static int DIR = 4;

static int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SZ][SZ];
static pii snake_loc;
static int snake_dir;
static pii apple[SZ];
static int order_time[SZ];
static char order[SZ];
static int N, K, L;
inline void print()
{
	register int r, c;
	for (r = 1; r <= N; ++r)
	{
		for (c = 1; c <= N; ++c)
			cout << map[r][c] << ' ';
		cout << "\n\n";
	}
}
inline void init()
{
	(void)memset(map, 0, sizeof(map));
	for (register int i = 0; i < SZ; ++i)
	{
		apple[i] = { 0, 0 };
		order_time[i] = 0;
		order[i] = ' ';
	}
	snake_loc = { 1, 1 };
	snake_dir = 1;
}
inline int simul()
{
	register int time = 0, cr, cc, nr, nc, order_idx = 0, a, len = 1;
	map[snake_loc.first][snake_loc.second] = 1;
	while (1)
	{
		time++;
		cr = snake_loc.first;
		cc = snake_loc.second;
		nr = cr + dir[snake_dir][0];
		nc = cc + dir[snake_dir][1];
		if (nr < 1 || nc < 1 || nr > N || nc > N || (len >= 3 && map[nr][nc] && map[nr][nc] > map[cr][cc] - len)) break;
		for (a = 0; a < K; ++a)
		{
			if (apple[a].first == nr && apple[a].second == nc)
			{
				apple[a] = { -1, -1 };
				len++;
				break;
			}
		}
		map[nr][nc] = time;
		snake_loc = { nr, nc };
		if (order_time[order_idx] == time)
		{
			if (order[order_idx] == 'L') snake_dir = (snake_dir + 3) % 4;
			else snake_dir = (snake_dir + 1) % 4;
			order_idx++;
		}
	}
	return time;
}
int main(int argc, char** argv)
{
	freopen("input3190.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	register int k, l;
	cin >> N;
	cin >> K;
	for (k = 0; k < K; ++k)
		cin >> apple[k].first >> apple[k].second;
	cin >> L;
	for (l = 0; l < L; ++l)
		cin >> order_time[l] >> order[l];
	cout << simul() << '\n';
	return 0;
}