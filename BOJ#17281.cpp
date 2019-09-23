//
//	OS Windows
//	2019.09.21
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17281 야구
//
//	ver.1 완전탐색
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 10;
static int N, ret;
static int table[MAX][MAX];
static int sel[MAX], check[MAX], base[4];
inline int cal_score()
{
	register int i, j, k, score = 0, cur_idx, cur, nxt, out, start_idx = 1;
	for (i = 0; i < N; ++i)
	{
		(void)memset(base, 0, sizeof(base));
		out = 0;
		j = start_idx;
		while (1)
		{
			if (j == 10) j = 1;
			cur_idx = sel[j];
			cur = table[i][cur_idx];
			if (!cur) out++;
			else
			{
				for (k = 3; k >= 1; --k)
				{
					if (base[k])
					{
						base[k] = 0;
						nxt = k + cur;
						if (nxt > 3) score++;
						else base[nxt] = 1;
					}
				}
				if (cur == 4) score++;
				else base[cur] = 1;
			}
			j++;
			if (out == 3) break;
		}
		start_idx = j;
	}
	return score;
}
inline void recur(int cnt)
{
	if (cnt == 4) recur(cnt + 1);
	if (cnt == MAX)
	{
		sel[4] = 1;
		int tmp = cal_score();
		if (ret < tmp) ret = tmp;
		return;
	}
	for (register int i = 2; i < MAX; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			sel[cnt] = i;
			recur(cnt + 1);
			check[i] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input17281.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i, j;
	ret = 0;
	cin >> N;
	for (i = 0; i < N; ++i)
	{
		for (j = 1; j < MAX; ++j)
		{
			cin >> table[i][j];
		}
	}
	(void)memset(check, 0, sizeof(check));
	recur(1);
	cout << ret;
	return 0;
}