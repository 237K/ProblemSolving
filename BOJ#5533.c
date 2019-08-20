//
//	OS Windows
//	2019.08.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5533	¿Ø¥œ≈©
//

#include <stdio.h>
int table[201][3];
int score[201];
int main(void)
{
	freopen("input5533.txt", "r", stdin);
	int N, r, c, i, cur;
	scanf("%d", &N);
	for (r = 0; r < N; ++r)
		for (c = 0; c < 3; ++c)
			scanf("%d", &table[r][c]);
	for (i = 0; i < N; ++i)
	{
		score[i] = 0;
		for (c = 0; c < 3; ++c)
		{
			cur = table[i][c];
			for (r = 0; r < N; ++r)
			{
				if (i == r) continue;
				if (cur == table[r][c])
				{
					cur = 0;
					break;
				}
			}
			score[i] += cur;
		}
	}
	for (i = 0; i < N; ++i) printf("%d\n", score[i]);
	return 0;
}