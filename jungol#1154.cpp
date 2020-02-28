//
//	OS Windows
//	2020.02.11
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1154> Red and Black
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
const static int SZ = 21;
const static int DIR = 4;
typedef pair<int, int> pii;
static char table[SZ][SZ];
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int check[SZ][SZ], W, H, start_row, start_col;
int simul()
{
	register int cr, cc, nr, nc, d, ret = 1;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	check[start_row][start_col] = 1;
	Q.push({ start_row, start_col });
	while (!Q.empty())
	{
		cr = Q.front().first;
		cc = Q.front().second;
		Q.pop();
		for (d = 0; d < DIR; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nr >= H || nc < 0 || nc >= W || check[nr][nc])
				continue;
			if (table[nr][nc] == '#')
				continue;
			Q.push({ nr, nc });
			check[nr][nc] = 1;
			ret++;
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("jinput1154.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> W >> H;
	register int r, c;
	for (r = 0; r < H; ++r)
	{
		cin >> table[r];
	}
	for (r = 0; r < H; ++r)
	{
		for (c = 0; c < W; ++c)
		{
			if (table[r][c] == '@')
			{
				start_row = r;
				start_col = c;
			}
		}
	}
	cout << simul();
	return 0;
}