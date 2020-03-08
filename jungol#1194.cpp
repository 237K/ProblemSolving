//
//	OS Windows
//	2020.03.03
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1194> 호수찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
const static int SZ = 100;
const static int DIR = 4;
typedef pair<int, int> pii;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], check[SZ][SZ], N, M, K, num_hosu;
static pii hosu[SZ * SZ];
inline int simul()
{
	register int cr, cc, k, d, nr, nc, cur, high = 0;
	queue<pii> Q;
	(void)memset(check, 0, sizeof(check));
	for (k = 0; k < num_hosu; ++k)
	{
		if (check[hosu[k].first][hosu[k].second]) continue;
		Q.push({ hosu[k].first, hosu[k].second });
		check[hosu[k].first][hosu[k].second] = 1;
		while (Q.empty()) { Q.pop(); }
		cur = 1;
		while (!Q.empty())
		{
			cr = Q.front().first;
			cc = Q.front().second;
			Q.pop();
			for (d = 0; d < DIR; ++d)
			{
				nr = cr + dir[d][0];
				nc = cc + dir[d][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M || check[nr][nc] || !map[nr][nc]) continue;
				cur++;
				Q.push({ nr, nc });
				check[nr][nc] = 1;
			}
		}
		if (high < cur) high = cur;
	}
	return high;
}
int main(int argc, char** argv)
{
	freopen("jinput1194.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	num_hosu = 0;
	int r, c, k;
	cin >> N >> M >> K;
	for (k = 0; k < K; ++k)
	{
		cin >> r >> c;
		r--; c--;
		map[r][c] = 1;
		hosu[num_hosu++] = { r, c };
	}
	cout << simul();
	return 0;
}