//
//	OS Windows
//	2020.02.20
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #14502>	연구소
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 8;
const static int MAX_VIRUS = 10;
const static int MAX_EMPTY = SZ * SZ;
const static int MAX_WALL = 3;
const static int DIR = 4;
static int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SZ][SZ], map_cpy[SZ][SZ], sel[MAX_WALL], N, M, num_virus, num_empty, ret;
static pii virus[MAX_VIRUS], emptyspace[MAX_EMPTY];
inline int spread()
{
	register int i, cr, cc, nr, nc, d, cnt = num_empty;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	for (i = 0; i < num_virus; ++i)
		Q.push(virus[i]);
	while (!Q.empty())
	{
		cr = Q.front().first;
		cc = Q.front().second;
		Q.pop();
		for (d = 0; d < DIR; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || map_cpy[nr][nc])
				continue;
			cnt--;
			map_cpy[nr][nc] = 2;
			Q.push({ nr, nc });
		}
	}
	return cnt;
}
inline void simul(int cnt, int idx)
{
	if (cnt == MAX_WALL)
	{
		(void)memcpy(map_cpy, map, sizeof(map));
		for (register int i = 0; i < MAX_WALL; ++i)
		{
			int cur_idx = sel[i];
			pii cur = emptyspace[cur_idx];
			map_cpy[cur.first][cur.second] = 1;
		}
		int cur_cnt = spread();
		if (ret < cur_cnt) ret = cur_cnt;
		return;
	}
	for (register int i = idx; i < num_empty; ++i)
	{
		sel[cnt] = i;
		simul(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input14502.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ret = num_virus = num_empty = 0;
	register int r, c;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			if (!map[r][c]) emptyspace[num_empty++] = { r, c };
			else if (map[r][c] == 2) virus[num_virus++] = { r, c };
		}
	}
	simul(0, 0);
	cout << ret - MAX_WALL;
	return 0;
}