//
//	OS Windows
//	2020.05.16
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <BOJ #14502> 연구소
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const static int SZ = 8;
const static int DIR = 4;
const static int WALL = 3;
typedef pair<int, int> pii;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static pii virus[SZ * SZ], pos_wall[SZ*SZ];
static int arr[SZ][SZ], arr_cpy[SZ][SZ], N, M, num_virus, num_pos_wall, sel[WALL], ret;
inline int check()
{
	register int cnt = 0, r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			if (!arr[r][c])
			{
				cnt++;
			}
		}
	}
	return cnt;
}
inline void spread()
{
	register int i, r, c, cr, cc, nr, nc, d, cur;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	for (i = 0; i < num_virus; ++i)
	{
		Q.push({ virus[i].first, virus[i].second });
	}
	while (!Q.empty())
	{
		cr = Q.front().first;
		cc = Q.front().second;
		Q.pop();
		for (d = 0; d < DIR; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || arr[nr][nc])
				continue;
			Q.push({ nr, nc });
			arr[nr][nc] = 2;
		}
	}
	cur = check();
	if (ret < cur)
		ret = cur;
}
inline void simul()
{
	(void)memcpy(arr, arr_cpy, sizeof(arr));
	register int i, r, c;
	for (i = 0; i < WALL; ++i)
	{
		r = pos_wall[sel[i]].first;
		c = pos_wall[sel[i]].second;
		arr[r][c] = 1;
	}
	spread();
}
inline void building(int cnt, int idx)
{
	if (cnt == WALL)
	{
		simul();
		return;
	}
	for (register int i = idx; i < num_pos_wall; ++i)
	{
		sel[cnt] = i;
		building(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input14502.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	register int r, c;
	num_virus = num_pos_wall = ret = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> arr[r][c];
			arr_cpy[r][c] = arr[r][c];
			if (!arr[r][c])
			{
				pos_wall[num_pos_wall++] = { r, c };
			}
			if (arr[r][c] == 2)
			{
				virus[num_virus++] = { r, c };
			}
		}
	}
	building(0, 0);
	cout << ret;
	return 0;
}