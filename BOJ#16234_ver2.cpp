//
//	OS Windows
//	2019.07.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16234	인구 이동
//	ver.2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 51;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int N, L, R;
static int map[SZ][SZ];
static int check[SZ][SZ];
static vector<pii> V[SZ * SZ];
inline int simul()
{
	register int i, r, c, cr, cc, nr, nc, d, tmp, num_group = 1, ret = 0;
	bool flag;
	queue<pii> Q;
	while (1)
	{
		for (i = 0; i < N * N; ++i) V[i].clear();
		(void)memset(check, 0, sizeof(check));
		flag = false;
		num_group = 1;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				if (!check[r][c])
				{
					check[r][c] = num_group;
					V[num_group].push_back({ r, c });
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
							if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc]) continue;
							tmp = map[cr][cc] - map[nr][nc]; if (tmp < 0) tmp *= -1;
							if (tmp >= L && tmp <= R)
							{
								if (!flag) flag = true;
								check[nr][nc] = num_group;
								V[num_group].push_back({ nr, nc });
								Q.push({ nr, nc });
							}
						}
					}
					num_group++;
				}
			}
		}
		if (!flag) break;
		ret++;
		for (i = 1; i <= num_group; ++i)
		{
			if (V[i].size() > 1)
			{
				int sum = 0, sz = V[i].size(), tmp;
				for (register int s = 0; s < sz; ++s) sum += map[V[i][s].first][V[i][s].second];
				tmp = sum / sz;
				for (register int s = 0; s < sz; ++s) map[V[i][s].first][V[i][s].second] = tmp;
			}
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input16234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	cin >> N >> L >> R;
	for (r = 0; r < N; ++r)
		for (c = 0; c < N; ++c)
			cin >> map[r][c];
	cout << simul();
	return 0;
}