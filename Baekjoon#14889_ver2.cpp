//
//	OS Windows
//	2019.03.30
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14889	스타트와 링크
//	ver2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const static int MAX = 21;
const static int INF = 2147000000;

static int N;
static int table[MAX][MAX];
static int check[MAX];
static int t_start[MAX / 2];
static int t_link[MAX / 2];
static int Result;

inline int Score()
{
	int s_start = 0;
	int s_link = 0;
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = 0; j < N / 2; ++j)
		{
			if (i != j)
			{
				s_start += table[t_start[i]][t_start[j]];
				s_link += table[t_link[i]][t_link[j]];
			}
		}
	}
	return abs(s_start - s_link);
}

inline void pick(int member)
{
	if (member >= N / 2)
	{
		int idx = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (!check[i])
			{
				t_link[idx++] = i;
				check[i] = true;
			}
		}
		Result = min(Result, Score());

		for (int i = 0; i < N/2; ++i)
		{
			check[t_link[i]] = false;
		}
		return;
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!check[i])
			{
				t_start[member] = i;
				check[i] = true;
				pick(member + 1);
				check[i] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input#14889.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	(void)memset(table, 0, sizeof(table));
	(void)memset(check, 0, sizeof(check));
	(void)memset(t_start, 0, sizeof(t_start));
	(void)memset(t_link, 0, sizeof(t_link));
	Result = INF;
	cin >> N;
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			cin >> table[r][c];
		}
	}
	pick(0);
	cout << Result;
	return 0;
}