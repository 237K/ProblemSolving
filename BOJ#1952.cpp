//
//	OS Windows
//	2019.05.22
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1952	¥ﬁ∆ÿ¿Ã2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int SZ = 100;
const static int DIRECT = 4;

static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SZ][SZ];
static int M, N;
inline int simul()
{
	int ret = 0, cr = 0, cc = 0, cd = 1, end_flag = 0;
	map[0][0] = 1;
	while (1)
	{
		end_flag = 0;
		int nr = cr + dir[cd][0];
		int nc = cc + dir[cd][1];
		if (nr < 0 || nc < 0 || nr > M - 1 || nc > N - 1 || map[nr][nc])
		{
			cd = (cd + 1) % 4;
			int nnr = cr + dir[cd][0];
			int nnc = cc + dir[cd][1];
			if (map[nnr][nnc]) break;
			else
			{
				ret++;
				nr = nnr;
				nc = nnc;
			}
		}
		map[nr][nc] = 1;
		cr = nr;
		cc = nc;
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input1952.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	cin >> M >> N;
	cout << simul();
	return 0;
}