//
//	OS Windows
//	2019.05.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2117> 홈 방범 서비스 (모의)
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 20
#define HOUSE SZ*SZ+1
#define COVERAGE SZ*2+1
int map[SZ][SZ];
int cost[COVERAGE];
int cover[HOUSE][COVERAGE];
int house_r[HOUSE], house_c[HOUSE];
int T, N, M, K, total_house;
int simulation();
int main(int argc, char** argv)
{
	freopen("s_input2117.txt", "r", stdin);
	register int i, test_case, r, c;
	for (i = 1; i < SZ + 2; ++i) cost[i] = i * i + (i - 1) * (i - 1);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(cover, 0, sizeof(cover));
		total_house = 0;
		scanf("%d %d", &N, &M);
		K = N;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				scanf("%d", &map[r][c]);
				if (map[r][c])
				{
					house_r[total_house] = r;
					house_c[total_house++] = c;
				}
			}
		}
		printf("#%d %d\n", test_case, simulation());
	}
	return 0;
}
int simulation()
{
	if (total_house * M >= cost[N]) return total_house;

	register int r, c, h, k, idx = 0, cnt = 0, r_dist, c_dist, dist, profit, ret = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			idx = r*N+c;
			for (h = 0; h < total_house; ++h)
			{
				r_dist = r - house_r[h]; if (r_dist < 0) r_dist *= -1;
				c_dist = c - house_c[h]; if (c_dist < 0) c_dist *= -1;
				dist = r_dist + c_dist;
				cover[idx][dist] += 1;
			}
			cnt = 0;
			for (k = 1; k <= K; ++k)
			{
				if (!cover[idx][k - 1]) continue;
				cnt += cover[idx][k-1];
				if (cnt < ret) continue;
				profit = cnt * M;
				if (profit < cost[k]) continue;
				else if (cnt > ret) ret = cnt;
			}
		}
	}
	return ret;
}