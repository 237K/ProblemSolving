//
//	OS Windows
//	2020.10.10
//
//	[PS][BOJ[#14889] 스타트와 링크
//	비트마스크로
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int SZ = 22;
static int map[SZ][SZ], N, team[2][SZ / 2], num_start, num_link;
inline int cal_diff()
{
	int sum[2] = { 0, 0 };
	register int t, i, j, p1, p2, diff;
	for (t = 0; t < 2; ++t)
	{
		for (i = 0; i < N / 2; ++i)
		{
			p1 = team[t][i];
			for (j = 0; j < N / 2; ++j)
			{
				p2 = team[t][j];
				sum[t] += map[p1][p2];
			}
		}
	}
	diff = sum[1] - sum[0];
	if (diff < 0) diff *= -1;
	return diff;
}
inline int comb()
{
	register int mask, flag, ret = 2147000000, diff, cnt;
	for (mask = 0; mask < (1 << N); ++mask)
	{
		cnt = num_start = num_link = 0;
		for (flag = 0; flag < N; ++flag)
		{
			if (mask & (1 << flag)) cnt++;
		}
		if (cnt != N / 2) continue;
		//	스타트팀 : 1 / 링크팀 : 0
		for (flag = 0; flag < N; ++flag)
		{
			if (mask & (1 << flag))
				team[1][num_start++] = flag + 1;
			else
				team[0][num_link++] = flag + 1;
		}
		diff = cal_diff();
		if (ret > diff) ret = diff;
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("binput14889.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	cin >> N;
	for (r = 1; r <= N; ++r)
	{
		for (c = 1; c <= N; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << comb();
	return 0;
}
