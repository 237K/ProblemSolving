//
//	OS Windows
//	2019.07.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1954] (D2) 달팽이 숫자
//

#include <iostream>
#include <memory.h>
using namespace std;
const static int SZ = 10;
const static int DIRECT = 4;
static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ];
static int T, N;
inline void go()
{
	register int i, cr, cc, nr, nc, d, cnt;
	cr = cc = d = cnt = 0;
	map[cr][cc] = i = 1;
	while (1)
	{
		nr = cr + dir[d][0]; nc = cc + dir[d][1];
		if (map[nr][nc])
		{	
			if (cnt < 4)
			{
				d = (d + 1) % 4;
				cnt++;
				continue;
			}
			else break;
		}
		if (nr < 0 || nc < 0 || nr > N - 1 || nc > N - 1)
		{
			d = (d+1) % 4;
			continue;
		}
		map[nr][nc] = ++i;
		cr = nr; cc = nc;
	}
}
inline void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << '\n';
	}
}
int main(int argc, char** argv)
{
	freopen("s_input1954.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(map, 0, sizeof(map));
		cin >> N;
		go();
		cout << "#" << tc << '\n'; print();
	}
	return 0;
}