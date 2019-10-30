
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 1001;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], check[SZ][SZ];
static pii start[SZ * SZ];
static int N, M, num_target, num_start;
inline void print()
{
	cout << "============================\n\n";
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cout << check[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "============================\n\n";
}
inline int simul()
{
	if (num_start == N * M) return 0;
	register int t, cr, cc, d, nr, nc, cnt = 0, sz, tik = 0;
	queue<pii> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	for (t = 0; t < num_start; ++t)
	{
		cr = start[t].first;
		cc = start[t].second;
		Q.push({ cr, cc });
		check[cr][cc] = 1;
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
			cr = Q.front().first;
			cc = Q.front().second;
			Q.pop();
			for (d = 0; d < DIR; ++d)
			{
				nr = cr + dir[d][0];
				nc = cc + dir[d][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc] || check[nr][nc]) continue;
				check[nr][nc] = 1;
				cnt++;
				Q.push({ nr, nc });
			}
		}
		//print();
	}
	return tik;
}
int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	num_target = num_start = 0;
	cin >> M >> N;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			if (!map[r][c]) num_target++;
			else if (map[r][c] == 1)
			{
				start[num_start++] = { r, c };
			}
		}
	}
	cout<<simul();
	return 0;
}