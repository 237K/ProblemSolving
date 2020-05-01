//
//	OS Windows
//	2020.04.30
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1750> 섬의 침몰
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 100;
const static int MAX = SZ * SZ;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static pii small_lake[MAX];
static int map[SZ][SZ], check[SZ][SZ], num_small_lake, R, C, connect_flag;
inline void print()
{
	register int r, c;
	cout << "=========================================\n\n";
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "=========================================\n\n";
}
inline void flooding()
{
	register int i, r, c, d, nr, nc, cnt, num_ToBeLocked = 0;
	pii ToBeLocked[MAX];
	for (r = 0 ; r < R ; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] == 1)
			{
				cnt = 0;
				for (d = 0; d < DIR; ++d)
				{
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C)
						continue;
					if (!connect_flag)
					{
						if (map[nr][nc] == 2)
							cnt++;
					}
					else
					{
						if (map[nr][nc] != 1)
							cnt++;
					}
				}
				if (cnt >= 2)
				{
					ToBeLocked[num_ToBeLocked++] = { nr, nc };
				}
			}
		}
	}
	for (i = 0; i < num_ToBeLocked; ++i)
	{
		map[ToBeLocked[i].first][ToBeLocked[i].second] = 2;
	}
}
inline int check_end()
{
	register int r, c, flag = 1;
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] == 1)
			{
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}
	return flag;
}
inline void check_connect()
{
	register int i, r, c, cr, cc, d, nr, nc;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	for (i = 0; i < num_small_lake; ++i)
	{
		r = small_lake[i].first;
		c = small_lake[i].second;
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
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || check[nr][nc] || map[nr][nc] == 1)
					continue;
				if (map[nr][nc] == 2)
				{
					connect_flag = 1;
					break;
				}
				Q.push({ nr, nc });
				check[nr][nc] = 1;
			}
		}
		if (connect_flag) break;
	}
}
inline void find_small_lake()
{
	register int r, c, flag = 0, cr, cc, d, nr, nc;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	//	큰호수 시작점을 찾아서
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (!map[r][c])
			{
				Q.push({ r, c });
				map[r][c] = 2;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	//	큰호수 클러스터링
	while (!Q.empty())
	{
		cr = Q.front().first;
		cc = Q.front().second;
		Q.pop();
		for (d = 0; d < DIR; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc])
				continue;
			Q.push({ nr, nc });
			map[nr][nc] = 2;
		}
	}
	//	작은호수 찾기 (큰호수랑 연결됐는지 확인할 때 빨리 하려고)
	num_small_lake = 0;
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (!map[r][c])
			{
				small_lake[num_small_lake++] = { r, c };
			}
		}
	}
}
inline int simul()
{
	connect_flag = 0;
	find_small_lake();
	register int cnt = 0;
	while (1)
	{
		cnt++;
		cout << cnt << '\n';
		print();
		flooding();
		if (!connect_flag) check_connect();
		if (check_end()) break;
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("jinput1750.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	register int r, c;
	cin >> C >> R;
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << simul();
	return 0;
}