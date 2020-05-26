//
//	OS Windows
//	2020.05.24
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#16234> 인구 이동
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 51;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], check[SZ][SZ], N, L, R;
static vector<pii> uni[SZ * SZ];
inline void vinit()
{
	register int i;
	for (i = 0; i < N * N; ++i)
		uni[i].clear();
}
inline void cal(int n_u)
{
	register int i, j, r, c, sz, sum, avg;
	for (i = 0; i < n_u; ++i)
	{
		sz = uni[i].size();
		sum = 0;
		for (j = 0; j < sz; ++j)
		{
			r = uni[i][j].first;
			c = uni[i][j].second;
			sum += map[r][c];
		}
		avg = sum / sz;
		for (j = 0; j < sz; ++j)
		{
			r = uni[i][j].first;
			c = uni[i][j].second;
			map[r][c] = avg;
		}
	}
}
inline int go()
{
	register int flag = 0, r, c, cr, cc, nr, nc, d, cur, nxt, diff, num_union = 0, num_nation;
	(void)memset(check, 0, sizeof(check));
	vinit();
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (check[r][c]) continue;
			num_nation = 1;
			uni[num_union].push_back({ r, c });
			Q.push({ r, c });
			check[r][c] = 1;
			while (!Q.empty())
			{
				cr = Q.front().first;
				cc = Q.front().second;
				Q.pop();
				for (d = 0; d < DIR; ++d)
				{
					nr = cr + dir[d][0];
					nc = cc + dir[d][1];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc])
						continue;
					cur = map[cr][cc];
					nxt = map[nr][nc];
					diff = cur - nxt;
					if (diff < 0) diff *= -1;
					if (diff < L || diff > R) continue;
					num_nation++;
					uni[num_union].push_back({ nr, nc });
					Q.push({ nr, nc });
					check[nr][nc] = 1;
				}
			}
			if (num_nation > 1)
			{
				num_union++;
			}
			else
			{
				uni[num_union].clear();
			}
		}
	}
	if (!num_union)
	{
		flag = 1;
	}
	else
	{
		cal(num_union);
	}
	return flag;
}
inline int simul()
{
	register int ret = 0;
	while (1)
	{
		if (go()) break;
		ret++;
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("jinput16234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << simul();
	return 0;
}