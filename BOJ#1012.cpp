//
//	OS Windows
//	2019.10.17
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1012	¿Ø±‚≥Û πË√ﬂ
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const static int DIR = 4;
const static int SZ = 51;
static int map[SZ][SZ];
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int check[SZ][SZ];
static int T, N, M, K;
inline int simul()
{
	if (K == 1) return 1;
	register int r, c, cr, cc, nr, nc, d, cnt = 0;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			if (map[r][c] && !check[r][c])
			{
				cnt++;
				check[r][c] = 1;
				Q.push({ r, c });
				while (!Q.empty())
				{
					cr = Q.front().first;
					cc = Q.front().second;
					Q.pop();
					for (d = 0; d < DIR; ++d)
					{
						nr = cr + dir[d][0];
						nc = cc + dir[d][1];
						if (nr < 0 || nc < 0 || nr >= N || nc >= M || !map[nr][nc] || check[nr][nc]) continue;
						Q.push({ nr, nc });
						check[nr][nc] = 1;
					}
				}
			}
		}
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("input1012.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc, k, r, c;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(map, 0, sizeof(map));
		cin >> M >> N >> K;
		for (k = 0; k < K; ++k)
		{
			cin >> c >> r;
			map[r][c] = 1;
		}
		cout << simul() << '\n';
	}
	return 0;
}