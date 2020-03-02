//
//	OS Windows
//	2020.02.21
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #15686>	치킨 배달
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int SZ = 50;
const static int MAX = 13;
typedef pair<int, int> pii;
static int map[SZ][SZ], sel[MAX], N, M, num_dak, num_house, ret;
static pii dak[MAX], house[SZ*2];
inline int cal_route()
{
	register int i, j, cr, cc, ci, tmp, tmpr, tmpc, low, cal = 0;
	for (i = 0; i < num_house; ++i)
	{
		low = 2147000000;
		cr = house[i].first;
		cc = house[i].second;
		for (j = 0; j < M; ++j)
		{
			ci = sel[j];
			tmpr = cr - dak[ci].first;
			tmpc = cc - dak[ci].second;
			if (tmpr < 0) tmpr *= -1;
			if (tmpc < 0) tmpc *= -1;
			tmp = tmpr + tmpc;
			if (low > tmp) low = tmp;
		}
		cal += low;
	}
	return cal;
}
inline void simul(int cnt, int idx)
{
	if (cnt == M)
	{
		int cur = cal_route();
		if (ret > cur) ret = cur;
	}
	for (register int j = idx; j < num_dak; ++j)
	{
		sel[cnt] = j;
		simul(cnt + 1, j + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input15686.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ret = 2147000000;
	num_dak = num_house = 0;
	cin >> N >> M;
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 1) house[num_house++] = { r, c };
			else if (map[r][c] == 2) dak[num_dak++] = { r, c };
		}
	}
	simul(0, 0);
	cout << ret;
	return 0;
}