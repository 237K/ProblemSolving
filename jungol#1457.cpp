//
//	OS Windows
//	2020.03.30
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1457> 영역 구하기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
const static int SZ = 100;
const static int DIR = 4;
typedef pair<int, int> pii;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int M, N, K;
static int table[SZ][SZ], check[SZ][SZ];
static vector<int> v;
inline void print()
{
	register int r, c;
	for (r = 0; r < M; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cout << table[r][c] << ' ';
		}
		cout << "\n\n";
	}
}
inline void fill(int lbx, int lby, int rtx, int rty)
{
	register int r, c;
	for (r = lby; r < rty; ++r)
		for (c = lbx; c < rtx; ++c)
			table[r][c] = 1;
}
inline void simul()
{
	v.clear();
	(void)memset(check, 0, sizeof(check));
	queue<pii> Q;
	register int r, c, cr, cc, nr, nc, d, cnt;
	for (r = 0; r < M; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (!table[r][c] && !check[r][c])
			{
				cnt = 1;
				check[r][c] = 1;
				Q.push({ r, c });
				while (!Q.empty())
				{
					cr = Q.front().first;
					cc = Q.front().second;
					Q.pop();
					for (d = 0; d < DIR; ++d)
					{
						nr = cr + dir[d][0];
						nc = cc + dir[d][1];
						if (nr < 0 || nc < 0 || nr >= M || nc >= N || table[nr][nc] || check[nr][nc])
							continue;
						cnt++;
						check[nr][nc] = 1;
						Q.push({ nr, nc });
					}
				}
				v.push_back(cnt);
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("jinput1457.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int k;
	int rtx, rty, lbx, lby;
	(void)memset(table, 0, sizeof(table));
	cin >> M >> N >> K;
	for (k = 0; k < K; ++k)
	{
		cin >> lbx >> lby >> rtx >> rty;
		fill(lbx, lby, rtx, rty);
	}
	simul();
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	return 0;
}