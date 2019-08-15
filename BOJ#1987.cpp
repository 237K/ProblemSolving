//
//	OS Windows
//	2019.08.06
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1987	¾ËÆÄºª
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, pii> string_and_pii;
const static int SZ = 21;
const static int DIR = 4;
static queue<string_and_pii> Q;
static int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static char map[SZ][SZ];
static int check[SZ][SZ];
static int R, C;
inline int simul()
{
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	register int d, nr, nc, flag, max_route = 0;
	string init, next;
	init.push_back(map[0][0]);
	Q.push({ init, {0, 0} });
	check[0][0] = 1;
	while (!Q.empty())
	{
		string cur_ch = Q.front().first;
		pii cur_loc = Q.front().second;
		Q.pop();
		cout << cur_ch << "\n";
		int cur_ch_len = cur_ch.length();
		if (max_route < cur_ch_len) max_route = cur_ch_len;
		for (d = 0; d < DIR; ++d)
		{
			nr = cur_loc.first + dir[d][0];
			nc = cur_loc.second + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			flag = 1;
			for (string::size_type i = 0; i < cur_ch.size(); ++i)
			{
				if (map[nr][nc] == cur_ch[i])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				// check[nr][nc] = 1;
				next.clear();
				next = cur_ch + map[nr][nc];
				Q.push({ next, {nr, nc} });
			}
		}
	}
	return max_route;
}
int main(int argc, char** argv)
{
	freopen("input1987.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r;
	cin >> R >> C;
	for (r = 0; r < R; ++r) cin >> map[r];
	cout << simul();
	return 0;
}