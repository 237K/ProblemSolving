////
//	OS Windows
//	2020.10.17
//	BAEKJOON #16234	인구 이동
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const static int DIR = 4;
const static int SZ = 51;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], check[SZ][SZ], N, L, R;
static pii group[SZ*SZ][SZ * SZ];
inline void cal(int num_group)
{
	register int i, num_nation, j, r, c, sum, avg;
	for (i = 0; i < num_group; ++i)
	{
		num_nation = group[i][0].first;
		sum = 0;
		for (j = 1; j < num_nation; ++j)
		{
			r = group[i][j].first;
			c = group[i][j].second;
			sum += map[r][c];
		}
		avg = sum / (num_nation - 1);
		for (j = 1; j < num_nation; ++j)
		{
			r = group[i][j].first;
			c = group[i][j].second;
			map[r][c] = avg;
		}
	}
}
inline int find()
{
	register int r, c, cr, cc, d, nr, nc, cur, diff, num_group = 0, num_nation;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (check[r][c]) continue;
			num_nation = 1;
			check[r][c] = 1;
			Q.push({ r, c });
			group[num_group][num_nation++] = { r, c };
			while (!Q.empty())
			{
				cr = Q.front().first;
				cc = Q.front().second;
				Q.pop();
				cur = map[cr][cc];
				for (d = 0; d < DIR; ++d)
				{
					nr = cr + dir[d][0];
					nc = cc + dir[d][1];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc]) continue;
					diff = cur - map[nr][nc];
					if (diff < 0) diff *= -1;
					if (diff >= L && diff <= R)
					{
						check[nr][nc] = 1;
						Q.push({ nr, nc });
						group[num_group][num_nation++] = { nr, nc };
					}
				}
			}
			if (num_nation > 2)
			{
				group[num_group++][0] = { num_nation, 0 };
			}
		}
	}
	return num_group;
}
inline int simul()
{
	register int num_group, cnt = 0;
	while (1)
	{
		num_group = find();
		if (!num_group) break;
		cal(num_group);
		cnt++;
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("binput16234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	(void)memset(map, 0, sizeof(map));
	cin >> N >> L >> R;
	for (r = 0; r < N; ++r)
		for (c = 0; c < N; ++c)
			cin >> map[r][c];
	cout << simul();
	return 0;
}