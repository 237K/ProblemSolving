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

inline int simul()
{
	register int cr, cc, nr, nc, d, nd, ret = 0, cnt;
	bool back_flag;
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
		for (d = 0; d < DIR; ++d)
		{
			nd = (d + 3) % 4;
			nr = cr + dir[nd][0];
			nc = cc + dir[nc][1];
			if (nr < 1 || nc < 1 || nr > N - 2 || nc > N - 2 || map[nr][nc])
			{
				cnt++;
				if (cnt == 4)
				{
					back_flag = true;
					break;
				}
				else continue;
			}
			robot_loc = { nr, nc };
			robot_dir = nd;
			break;
		}
		if (back_flag)
		{
			nd = (robot_dir + 2) % 4;
			nr = robot_loc.first + dir[nd][0];
			nc = robot_loc.second + dir[nd][1];
			if (nr < 1 || nc < 1 || nr > N - 2 || nc > N - 2 || map[nr][nc] == 1) break;
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
	(void)memset(map, 1, sizeof(map));
	register int r, c;
	cin >> N >> M >> init_r >> init_c >> init_d;
	robot_loc = { init_r, init_c };
	robot_dir = init_d;
	for (r = 1; r < N-1; ++r)
		for (c = 1; c < M-1; ++c)
			cin >> map[r][c];
	
	return 0;
}