//
//	OS Windows
//	2019.09.06
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14502	연구소
//

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int DIR = 4;
const static int SZ = 9;
const static int WALL = 3;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], map_cpy[SZ][SZ];
static int N, M, num_virus, num_empty, ret;
static pii virus[10], emp[65];
static int select[WALL];
inline int check()
{
	register int r, c, safety = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			if (!map[r][c]) safety++;
		}
	}
	return safety;
}
inline void spread()
{
	register int i, cr, cc, d, nr, nc;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	for (i = 0; i < num_virus; ++i) Q.push(virus[i]);
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
			map[nr][nc] = 3;
			Q.push({ nr, nc });
		}
	}
}
inline void recur(int cnt, int idx)
{
	if (cnt == WALL)
	{
		//	초기화
		(void)memcpy(map, map_cpy, sizeof(map));
		//	벽 설치
		for (register int s = 0; s < WALL; ++s)
		{
			map[emp[select[s]].first][emp[select[s]].second] = 3;
		}
		//	확산
		spread();
		//	안전영역 체크
		int tmp = check();
		if (ret < tmp) ret = tmp;
		return;
	}
	for (register int i = idx; i < num_empty; ++i)
	{
		select[cnt] = i;
		recur(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input14502.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	num_virus = num_empty = ret = 0;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> map_cpy[r][c];
			if (!map_cpy[r][c]) emp[num_empty++] = { r, c };
			else if (map_cpy[r][c] == 2) virus[num_virus++] = { r, c };
		}
	}
	recur(0, 0);
	cout << ret;
	return 0;
}