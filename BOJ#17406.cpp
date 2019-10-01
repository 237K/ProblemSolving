//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17406 배열 돌리기4
//

#include <iostream>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
const static int SZ = 51;
const static int MAX = 6;
static int map[SZ][SZ], map_cpy[SZ][SZ];
static ppi magic[MAX];
static int order[MAX], check[MAX];
static int N, M, K, ret;

inline void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		cout << "  ";
		for (c = 0; c < N; ++c)
		{
			cout << map[r][c] << "  ";
		}
		cout << "\n\n";
	}
}
inline void abdacadabra(int r, int c, int range)
{
	register int rr, rc, tmp1, tmp2, tmp3;

	tmp1 = map[r - range][c + range];
	for (rc = c + range; rc > c - range; --rc) map[r - range][rc] = map[r - range][rc - 1];

	tmp2 = map[r + range][c + range];
	for (rr = r + range; rr > r - range + 1; --rr) map[rr][c + range] = map[rr - 1][c + range];
	map[r - range + 1][c + range] = tmp1;

	tmp3 = map[r + range][c - range];
	for (rc = c - range; rc < c + range - 1; ++rc) map[r + range][rc] = map[r + range][rc + 1];
	map[r + range][c + range - 1] = tmp2;

	for (rr = r - range; rr < r + range - 1; ++rr) map[rr][c - range] = map[rr + 1][c - range];
	map[r + range - 1][c - range] = tmp3;
}
inline int cal()
{
	register int r, c, sum, min_value = 2147000000;
	for (r = 1; r <= N; ++r)
	{
		sum = 0;
		for (c = 1; c <= M; ++c)
		{
			sum += map[r][c];
		}
		if (min_value > sum) min_value = sum;
	}
	return min_value;
}
inline void simul(int cnt)
{
	if (cnt == K)
	{
		(void)memcpy(map, map_cpy, sizeof(map));
		register int ci, cr, cc, range, k, m, tmp;
		for (k = 0; k < K; ++k)
		{
			ci = order[k];
			cr = magic[ci].first.first;
			cc = magic[ci].first.second;
			range = magic[ci].second;
			for (m = range; m > 0; --m)
			{
				abdacadabra(cr, cc, m);
			}
		}
		tmp = cal();
		if (ret > tmp) ret = tmp;
		return;
	}
	for (register int i = 0; i < K; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			order[cnt] = i;
			simul(cnt + 1);
			check[i] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input17406.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c, k;
	cin >> N >> M >> K;
	for (r = 1; r <= N; ++r)
	{
		for (c = 1; c <= M; ++c)
		{
			cin >> map[r][c];
			map_cpy[r][c] = map[r][c];
		}
	}
	for (k = 0; k < K; ++k)
		cin >> magic[k].first.first >> magic[k].first.second >> magic[k].second;
	ret = 2147000000;
	(void)memset(check, 0, sizeof(check));
	simul(0);
	cout << ret;
	return 0;
}