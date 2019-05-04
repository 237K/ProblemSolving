//
//	OS Windows
//	2019.05.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14391	종이 조각
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int map[4][4] = { 0, };

int bitmask()
{
	int result = 0;
	for (register int mask = 0; mask < (1 << (N * M)); ++mask)
	{
		int temp = 0;
		//	가로 : mask = 0
		for (register int r = 0; r < N; ++r)
		{
			int garo = 0;
			for (register int c = 0; c < M; ++c)
			{
				int cur_idx = r * M + c;
				if ((mask & (1 << cur_idx)) == 0)
				{
					garo = garo * 10 + map[r][c];
				}
				else
				{
					temp += garo;
					garo = 0;
				}
			}
			temp += garo;
		}

		//	세로 : mask = 1
		for (register int c = 0; c < M; ++c)
		{
			int sero = 0;
			for (register int r = 0; r < N; ++r)
			{
				int cur_idx = r * M + c;
				if ((mask & (1 << cur_idx)))
				{
					sero = sero * 10 + map[r][c];
				}
				else
				{
					temp += sero;
					sero = 0;
				}
			}
			temp += sero;
		}
		if (result < temp)	result = temp;
	}
	return result;
}

int main(int argc, char** argv)
{
	freopen("input14391.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			scanf("%1d", &map[r][c]);
		}
	}
	printf("%d", bitmask());
	return 0;
}