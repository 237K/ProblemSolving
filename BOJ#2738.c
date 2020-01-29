//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2738>	Çà·Ä µ¡¼À
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
int matrix[2][SZ][SZ], N, M;
int main(void)
{
	freopen("input2738.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int i, r, c;
	for (i = 0; i < 2; ++i)
	{
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < M; ++c)
			{
				scanf("%d", &matrix[i][r][c]);
				if (i)
				{
					printf("%d ", matrix[0][r][c] + matrix[1][r][c]);
				}
			}
			if(i && r < N-1) printf("\n");
		}
	}
	return 0;
}