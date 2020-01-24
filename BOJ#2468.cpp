//
//	OS Windows
//	2019.10.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2468	안전 영역
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 101;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], check[SZ][SZ];
static int N;
inline int simul(int max_height)
{
	register int rain, r, c, cr, cc, d, nr, nc, cnt, ret = 1;
	queue<pii> Q;
	for (rain = 1; rain < max_height; ++rain)
	{
		(void)memset(check, 0, sizeof(check));
		while (!Q.empty()) { Q.pop(); }
		cnt = 0;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				if (map[r][c] > rain && !check[r][c])
				{
					Q.push({ r, c });
					check[r][c] = 1;
					cnt++;
					while (!Q.empty())
					{
						cr = Q.front().first;
						cc = Q.front().second;
						Q.pop();
						for (d = 0; d < DIR; ++d)
						{
							nr = cr + dir[d][0];
							nc = cc + dir[d][1];
							if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc] || map[nr][nc] <= rain) continue;
							check[nr][nc] = 1;
							Q.push({ nr, nc });
						}
					}
				}
			}
		}
		if (ret < cnt) ret = cnt;
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input2468.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r, c, max_height = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (max_height < map[r][c]) max_height = map[r][c];
		}
	}
	cout << simul(max_height);
	return 0;
}