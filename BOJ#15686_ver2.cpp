//
//	OS Windows
//	2019.07.27
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15686	치킨 배달
//	ver.2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const static int SZ = 51;
const static int MAX = 13;
static int map[SZ][SZ];
static pii home[2 * SZ];
static pii chicken[MAX];
static int N, M, H, K;
inline int cal_dist(int cr, int cc)
{
	register int i, r_dist, c_dist, dist, min_dist = 2147000000;
	for (i = 0; i < H; ++i)
	{
		r_dist = cr - home[i].first; if (r_dist < 0) r_dist *= -1;
		c_dist = cc - home[i].second; if (c_dist < 0) c_dist *= -1;
		dist = r_dist + c_dist;
		if (min_dist > dist) min_dist = dist;
	}
	return min_dist;
}
inline int simul()
{
	register int mask, flag, cnt, r, c, dist, ret = 2147000000;
	for (mask = 0; mask < (1 << K); ++mask)
	{
		cnt = dist = 0;
		for (flag = 0; flag < K; ++flag)
		{
			if (mask & (1 << flag)) cnt++;
			if (cnt > M) break;
		}
		if (cnt != M) continue;
		for (flag = 0; flag < K; ++flag)
		{
			if (mask & (1 << flag))
			{
				dist += cal_dist(chicken[flag].first, chicken[flag].second);
			}
		}
		if (ret > dist) ret = dist;
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input15686.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	register int r, c, K = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 1) home[H++] = { r, c };
			else if (map[r][c] == 2) chicken[K++] = { r, c };
		}
	}
	cout << simul();
	return 0;
}