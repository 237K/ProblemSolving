//
//	OS Windows
//	2019.03.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2805> (D3) 농작물 수확하기
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const static int MAX = 50;
static int N;
static int map[MAX][MAX];
inline bool possible(int r, int c);

int main(int argc, char** argv)
{
	freopen("s_input2805.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0;
		(void)memset(map, 0, sizeof(map));
		scanf("%d", &N);
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				scanf("%1d", &map[r][c]);
				if (!map[r][c])
					continue;
				if (possible(r, c))
					result += map[r][c];
			}
		}
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}

inline bool possible(int r, int c)
{
	int center = N / 2;
	return (abs(center - r) + abs(center - c)) <= center;
}