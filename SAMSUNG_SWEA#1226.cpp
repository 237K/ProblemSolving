//
//	OS Windows
//	2019.07.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1226] (D4) ¹Ì·Î1
//

#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

const static int SZ = 16;
const static int DIRECT = 4;
static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static string map[SZ];
static bool check[SZ][SZ];
inline pii find_start_point()
{
	register int r, c;
	for (r = 0; r < SZ; ++r)
	{
		for (c = 0; c < SZ; ++c)
		{
			if (map[r][c] == '2') return { r, c };
		}
	}
}
inline int navi()
{
	(void)memset(check, 0, sizeof(check));
	pii start = find_start_point();
	queue<pii> Q;
	Q.push(start);
	check[start.first][start.second] = true;
	while (!Q.empty())
	{
		pii cur = Q.front();
		Q.pop();
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nr = cur.first + dir[d][0];
			int nc = cur.second + dir[d][1];
			if (map[nr][nc] == '3') return 1;
			if (nr < 0 || nc < 0 || nr >= SZ || nc >= SZ || map[nr][nc] == '1' || check[nr][nc]) continue;
			else
			{
				check[nr][nc] = true;
				Q.push({ nr, nc });
			}
		}
	}
	return 0;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int tc, r, c;
	for (tc = 1; tc <= 10; ++tc)
	{
		cin >> T;
		for (r = 0; r < SZ; ++r) cin >> map[r];
		cout << "#" << T << ' ' << navi() << '\n';
	}
	return 0;
}