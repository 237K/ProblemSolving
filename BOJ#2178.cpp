
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
const static int SZ = 102;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int N, M;
char map[SZ][SZ];
int check[SZ][SZ];
inline int simul()
{
	register int cr, cc, d, nr, nc, cnt, ret = -1;
	queue<ppi> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	check[0][0] = 1;
	Q.push({ { 0, 0 }, 1 });
	while (!Q.empty())
	{
		cr = Q.front().first.first;
		cc = Q.front().first.second;
		cnt = Q.front().second;
		Q.pop();
		if (cr == N - 1 && cc == M - 1)
		{
			ret = cnt;
			break;
		}
		for (d = 0; d < DIR; ++d)
		{
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc] == '0' || check[nr][nc]) continue;
			check[nr][nc] = 1;
			Q.push({ {nr, nc}, cnt + 1 });
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		cin >> map[r];
	}
	cout << simul();
	return 0;
}