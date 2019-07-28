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
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 51;
const static int MAX = 13;
static int map[SZ][SZ];
static pii home[2 * SZ];
static pii chicken[MAX];
static pii alive[MAX];
static int N, M, H, K;
inline int cal_dist()
{
	register int i, j, r_dist, c_dist, tmp, min_dist, dist = 0;
	for (i = 0; i < H; ++i)
	{
		min_dist = 2147000000;
		for (j = 0; j < M; ++j)
		{
			r_dist = home[i].first - alive[j].first; if (r_dist < 0) r_dist *= -1;
			c_dist = home[i].second - alive[j].second; if (c_dist < 0) c_dist *= -1;
			tmp = r_dist + c_dist;
			//cout << "home : (" << home[i].first << ", " << home[i].second << "), chicken : (" << alive[j].first << ", " << alive[j].second << ") dist : "<<tmp<<"\n";
			if (min_dist > tmp) min_dist = tmp;
		}
		dist += min_dist;
	}
	return dist;
}
inline int simul()
{
	register int mask, flag, cnt, dist, ret = 2147000000;
	for (mask = 0; mask < (1 << K); ++mask)
	{
		cnt = dist = 0;
		for (flag = 0; flag < K; ++flag)
		{
			if (mask & (1 << flag)) cnt++;
			if (cnt > M) break;
		}
		if (cnt == M)
		{
			for (flag = 0; flag < K; ++flag)
			{
				if (mask & (1 << flag))
				{
					alive[--cnt] = chicken[flag];
				}
			}
			dist = cal_dist();
			if (ret > dist) ret = dist;
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input15686.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	register int r, c;
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