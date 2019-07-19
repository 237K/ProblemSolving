//
//	OS Windows
//	2019.07.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1227] (D4) ¹Ì·Î2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <memory.h>
using namespace std;
typedef pair<int, int> coor;
const static int SZ = 100;
const static int DIRECT = 4;
static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static string map[SZ];
static int check[SZ][SZ];
static stack<coor> S;
static coor start;
inline void init()
{
	(void)memset(check, 0, sizeof(check));
	for (register int r = 0; r < SZ; ++r) map[r].clear();
	while (!S.empty()) { S.pop(); }
}
inline void print_map()
{
	register int r;
	for (r = 0; r < SZ; ++r)
		cout << map[r] << '\n';
	cout << "\n\n";
}
inline void find_starting_point()
{
	register int r, c;
	bool flag = false;
	for (r = 0; r < SZ; ++r)
	{
		for (c = 0; c < SZ; ++c)
		{
			if (map[r][c] == '2')
			{
				start = { r, c };
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
}
inline int find_route()
{
	find_starting_point();
	register int cr, cc, nr, nc, d;
	S.push(start);
	check[start.first][start.second] = 1;
	while (!S.empty())
	{
		//print_map();
		coor cur = S.top();
		S.pop();
		cr = cur.first;
		cc = cur.second;
		for (d = 0; d < DIRECT; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= 100 || nc >= 100 || map[nr][nc] == '1' || check[nr][nc]) continue;
			if (map[nr][nc] == '3') return 1;
			S.push({ nr, nc });
			check[nr][nc] = 1;
			map[nr][nc] = '*';
		}
	}
	return 0;
}
int main(int argc, char** argv)
{
	freopen("s_input1227.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int tc, r;
	for (tc = 1; tc <= 10; ++tc)
	{
		init();
		cin >> T;
		for (r = 0; r < SZ; ++r) cin >> map[r];
		cout << "#" << tc << ' ' << find_route() << '\n';
	}
	return 0;
}