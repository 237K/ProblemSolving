//
//	OS Windows
//	2019.11.28
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç]	<BOJ #4659>	¹Ù´Ú Àå½Ä
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 101
char map[MAX][MAX], check[MAX][MAX];
int N, M;
int cal()
{
	(void)memset(check, 0, sizeof(check));
	register int r, rr, c, cc, sero = 0, garo = 0;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			if (map[r][c] == '-' && !check[r][c])
			{
				garo++;
				check[r][c] = 1;
				for (cc = c + 1; cc < M; ++cc)
				{
					if (map[r][cc] == '-')
					{
						check[r][cc] = 1;
					}
					else break;
				}
			}
		}
	}
	for (c = 0; c < M; ++c)
	{
		for (r = 0; r < N; ++r)
		{
			if (map[r][c] == '|' && !check[r][c])
			{
				sero++;
				check[r][c] = 1;
				for (rr = r + 1; rr < N; ++rr)
				{
					if (map[rr][c] == '|')
					{
						check[rr][c] = 1;
					}
					else break;
				}
			}
		}
	}
	return garo + sero;
}
int main(void)
{
	freopen("input1388.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int r;
	for (r = 0; r < N; ++r)
		scanf("%s", &map[r]);
	printf("%d", cal());
	return 0;
}