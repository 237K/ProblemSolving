//
//	OS Windows
//	2019.07.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14502	¿¬±¸¼Ò
//	ver.3
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 8;
const static int WALL = 3;
const static int DIR = 4;
static int dir[DIR][2] = { { -1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int N, M, es, v, ret;
static int map[SZ][SZ];
static int map_cpy[SZ][SZ];
static vector<pii> candidate;
static vector<pii> virus;
static queue<pii> Q;
static int wall[WALL];
inline void spread()
{
	register int i, d, cr, cc, nr, nc;
	for (i = 0; i < v; ++i) Q.push({ virus[i] });
	while (!Q.empty())
	{
		cr = Q.front().first;
		cc = Q.front().second;
		Q.pop();
		for (d = 0; d < DIR; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc]) continue;
			map[nr][nc] = 4;
			Q.push({ nr, nc });
		}
	}
}
inline int count()
{
	register int cnt = 0, r, c;
	for (r = 0; r < N; ++r)
		for (c = 0; c < M; ++c)
			if (!map[r][c]) cnt++;
	return cnt;
}
inline void recur(int cnt, int idx)
{
	if (cnt == 3)
	{
		for (register int i = 0; i < WALL; ++i) map[candidate[wall[i]].first][candidate[wall[i]].second] = 3;
		spread();
		int tmp = count();
		if (ret < tmp) ret = tmp;
		(void)memcpy(map, map_cpy, sizeof(map));
	}
	if (cnt > 3) return;
	for (register int i = idx; i < es; ++i)
	{
		wall[cnt] = i;
		recur(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input14502.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	candidate.clear();
	virus.clear();
	while (!Q.empty()) { Q.pop(); }
	es = ret = 0;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			map_cpy[r][c] = map[r][c];
			if (!map[r][c]) candidate.push_back({ r, c });
			else if (map[r][c] == 2) virus.push_back({ r, c });
		}
	}
	es = candidate.size();
	v = virus.size();
	recur(0, 0);
	cout << ret;
	return 0;
}