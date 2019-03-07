//
//	OS Windows
//	2019.03.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6730] <장애물 경주 난이도> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const static int INF = 2147000000;
const static int minINF = -2147000000;
const static int MAX_BLOCK = 100;
const static int MAX_HEIGHT = 1000;

static int N;
static int Block[MAX_BLOCK];
static int Height[MAX_BLOCK];
static int Max_up;
static int Max_down;

int main(int argc, char** argv)
{
	freopen("s_input6730.txt", "r", stdin);
	int T;
	int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0;	Max_up = minINF;	Max_down = INF;
		for (int i = 0; i < MAX_BLOCK; ++i)
		{
			Block[i] = 0;
			Height[i] = 0;
		}

		scanf("%d", &N);
		for (int n = 0; n < N; ++n)
		{
			scanf("%d", &Block[n]);
			if (n >= 1)
			{
				Height[n] = Block[n] - Block[n - 1];
				if (Height[n] > 0)
				{
					Max_up = Max_up < Height[n] ? Height[n] : Max_up;
				}
				else if (Height[n] < 0)
				{
					Max_down = Max_down > Height[n] ? Height[n] : Max_down;
				}
			}
		}

		if (Max_up == minINF)
			Max_up = 0;
		if (Max_down == INF)
			Max_down = 0;
		else if (Max_down < 0)
			Max_down *= -1;

		printf("#%d %d %d\n", test_case, Max_up, Max_down);
	}
	return 0;
}