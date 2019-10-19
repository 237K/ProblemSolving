#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
const static int SZ = 101;
const static int DIR = 6;
static int dir[DIR][3] = { {0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1} };
static int map[SZ][SZ][SZ], check[SZ][SZ][SZ];
static ppi start[SZ * SZ * SZ];
static int M, N, H, num_start, num_target;
inline int simul()
{
	if (!num_target) return 0;
	register int t, cr, cc, cz, d, nr, nc, nz, sz, cnt = 0, tik = 0;
	queue<ppi> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	for (t = 0; t < num_start; ++t)
	{
		cr = start[t].first.first;
		cc = start[t].first.second;
		cz = start[t].second;
		Q.push({ {cr, cc}, cz });
		check[cr][cc][cz] = 1;
	}
	while (1)
	{
		if (cnt == num_target) break;
		sz = Q.size();
		if (!sz)
		{
			tik = -1;
			break;
		}
		tik++;
		while (sz--)
		{
			cr = Q.front().first.first;
			cc = Q.front().first.second;
			cz = Q.front().second;
			Q.pop();
			for (d = 0; d < DIR; ++d)
			{
				nr = cr + dir[d][0];
				nc = cc + dir[d][1];
				nz = cz + dir[d][2];
				if (nr < 0 || nc < 0 || nz < 0 || nr >= N || nc >= M || nz >= H || map[nr][nc][nz] || check[nr][nc][nz]) continue;
				check[nr][nc][nz] = 1;
				Q.push({ {nr, nc}, nz });
				cnt++;
			}
		}
	}
	return tik;
}
int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c, z;
	cin >> M >> N >> H;
	num_start = num_target = 0;
	for (z = 0; z < H; ++z)
	{
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < M; ++c)
			{
				cin >> map[r][c][z];
				if (!map[r][c][z]) num_target++;
				else if (map[r][c][z] == 1)
					start[num_start++] = { {r, c}, z };
			}
		}
	}
	cout << simul();
	return 0;
}