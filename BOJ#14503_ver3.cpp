//
//	OS Windows
//	2019.07.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14503	·Îº¿ Ã»¼Ò±â
//	ver.3
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 50;
const static int DIR = 4;

static int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SZ][SZ];
static pii robot_loc;
static int robot_dir;
static int N, M, init_r, init_c, init_d;

//inline void print()
//{
//	register int r, c;
//	for (r = 0; r < N; ++r)
//	{
//		for (c = 0; c < M; ++c)
//		{
//			cout << map[r][c] << ' ';
//		}
//		cout << "\n\n";
//	}
//	cout << "====================================\n\n";
//}
inline int simul()
{
	register int cr, cc, nr, nc, nd, ret = 0, cnt;
	bool back_flag, end_flag;
	while (1)
	{
		cr = robot_loc.first;
		cc = robot_loc.second;
		if (!map[cr][cc])
		{
			map[cr][cc] = 2;
			ret++;
		}
		cnt = back_flag = end_flag = 0;
		while (1)
		{
			cr = robot_loc.first;
			cc = robot_loc.second;
			nd = (robot_dir + 3) % 4;
			robot_dir = nd;
			nr = cr + dir[nd][0];
			nc = cc + dir[nd][1];
			if (nr < 1 || nc < 1 || nr > N - 2 || nc > N - 2 || map[nr][nc])
			{
				if (++cnt == 4)
				{
					back_flag = true;
					break;
				}
				else continue;
			}
			robot_loc = { nr, nc };
			break;
		}
		print();
		if (back_flag)
		{
			nd = (robot_dir + 2) % 4;
			cr = robot_loc.first;
			cc = robot_loc.second;
			nr = cr + dir[nd][0];
			nc = cc + dir[nd][1];
			if (map[nr][nc] == 1) break;
			robot_loc = { nr, nc };
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	freopen("input14503.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	register int r, c;
	cin >> N >> M >> init_r >> init_c >> init_d;
	robot_loc = { init_r, init_c };
	robot_dir = init_d;
	for (r = 0; r < N; ++r)
		for (c = 0; c < M; ++c)
			cin >> map[r][c];
	cout << simul();
	return 0;
}