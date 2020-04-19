//
//	OS Windows
//	2020.04.19
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1695> 단지번호붙이기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 26;
const static int MAX = SZ * SZ;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int check[SZ][SZ], N;
static char map[SZ][SZ];
static vector<int> group;
inline void simul()
{
	(void)memset(check, 0, sizeof(check));
	register int r, c, d, cr, cc, nr, nc, cnt, sz, i;
	queue<pii> Q;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (map[r][c] == '1' && !check[r][c])
			{
				Q.push({ r, c });
				check[r][c] = 1;
				cnt = 1;
				while (!Q.empty())
				{
					cr = Q.front().first;
					cc = Q.front().second;
					Q.pop();
					for (d = 0; d < DIR; ++d)
					{
						nr = cr + dir[d][0];
						nc = cc + dir[d][1];
						if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc] || map[nr][nc] == '0')
							continue;
						Q.push({ nr, nc });
						check[nr][nc] = 1;
						cnt++;
					}
				}
				group.push_back(cnt);
			}
		}
	}
	sort(group.begin(), group.end());
	sz = group.size();
	cout << sz << '\n';
	for (i = 0; i < sz; ++i)
		cout << group[i] << '\n';
}
int main(int argc, char** argv)
{
	freopen("jinput1695.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r;
	for (r = 0; r < N; ++r)
	{
		cin >> map[r];
	}
	simul();
	return 0;
}