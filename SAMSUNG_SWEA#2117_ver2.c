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
#define SZ 20
int map[SZ][SZ];
int N, M, K, total_house;
int simulation();
int check(int r, int c, int k);
int main(int argc, char** argv)
{
	freopen("s_input2117.txt", "r", stdin);
	int T, test_case;
	register int r, c;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		total_house = 0;
		scanf("%d %d", &N, &M);
		K = N;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				scanf("%d", &map[r][c]);
				if (map[r][c]) total_house++;
			}
		}
		printf("#%d %d\n", test_case, simulation());
	}
	return 0;
}
int simulation()
{
	if (total_house * M >= (N + 1)*(N + 1) + N * N) return total_house;
	int ret = 0;
	register int r, c, k, num_house, profit, cost;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			for (k = 1; k <= K; ++k)
			{
				num_house = check(r, c, k);
				if (ret > num_house) continue;
				profit = num_house * M;
				cost = k * k + (k - 1)*(k - 1);
				if (profit < cost) continue;
				else
				{
					if (ret < num_house) ret = num_house;
				}
			}
		}
	}
	return ret;
}
int check(int r, int c, int k)
{
	register int tr, tc;
	int cnt = 0;
	for (tr = r - k + 1; tr <= r + k - 1; ++tr)
	{
		for (tc = c - k + 1; tc <= c + k - 1; ++tc)
		{
			if (tr < 0 || tc < 0 || tr > N - 1 || tc > N - 1) continue;
			int dr = r - tr; if (dr < 0) dr *= -1;
			int dc = c - tc; if (dc < 0) dc *= -1;
			int dd = dr + dc;
			if (dd > k-1) continue;
			else
			{
				if (map[tr][tc]) cnt++;
			}
		}
	}
	return cnt;
}