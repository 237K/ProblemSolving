//
//	OS Windows
//	2019.07.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15685	µå·¡°ï Ä¿ºê
//	ver.2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 101;
const static int DIR = 4;
const static int DIR_CHECK = 3;
static int dir_check[DIR_CHECK][2] = { {0, 1}, {1, 0}, {1, 1} };
static int dir[DIR][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
static int N;
static int map[SZ][SZ];

inline void dragon_curve(int r, int c, int d, int g)
{
	register int sz, i, nr, nc;
	vector<int> dc;
	dc.push_back(d);
	while (g--)
	{
		sz = dc.size();
		for(i = sz-1 ; i >= 0 ; --i)
			dc.push_back((dc[i] + 1) % 4);
	}
	sz = dc.size();
	map[r][c] = 1;
	for (i = 0; i < sz; ++i)
	{
		nr = r + dir[dc[i]][0];
		nc = c + dir[dc[i]][1];
		if (nr < 0 || nc < 0 || nr >= SZ || nc >= SZ) continue;
		map[nr][nc] = 1;
		r = nr; c = nc;
	}
}
inline int count()
{
	register int r, c, d, nr, nc, cnt = 0;
	bool flag;
	for (r = 0; r < SZ-1; ++r)
	{
		for (c = 0; c < SZ-1; ++c)
		{
			flag = true;
			if (map[r][c])
			{
				for (d = 0; d < DIR_CHECK; ++d)
				{
					nr = r + dir_check[d][0];
					nc = c + dir_check[d][1];
					if (!map[nr][nc])
					{
						flag = false;
						break;
					}
				}
				if (flag) cnt++;
			}
		}
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("input15685.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	int x, y, d, g;
	register int n;
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> x >> y >> d >> g;
		dragon_curve(y, x, d, g);
	}
	cout << count();
	return 0;
}