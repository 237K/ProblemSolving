//
//	OS Windows
//	2019.11.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1100	го╬А д╜
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 8
char map[SZ][SZ];
int main(void)
{
	freopen("input1100.txt", "r", stdin);
	register int r, c, cnt = 0;
	for (r = 0; r < SZ; ++r)
		scanf("%s", &map[r]);
	for (r = 0; r < SZ; ++r)
	{
		if (!(r % 2))
		{
			for (c = 0; c < SZ; ++c)
			{
				if (c % 2) continue;
				if (map[r][c] == 'F') cnt++;
			}
		}
		else
		{
			for (c = 0; c < SZ; ++c)
			{
				if (!(c % 2)) continue;
				if (map[r][c] == 'F') cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}