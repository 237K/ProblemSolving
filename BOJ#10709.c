//
//	OS Windows
//	2019.08.04
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON <#10709> 기상캐스터
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char map[101][101];
int ret[101][101];
int H, W;
void print()
{
	register int r, c;
	for (r = 0; r < H; ++r)
	{
		for (c = 0; c < W; ++c)
		{
			printf("%d ", ret[r][c]);
		}
		printf("\n");
	}
}
void weather()
{
	register int r, c, i, flag;
	for (r = 0; r < H; ++r)
	{
		for (c = W-1; c >= 0; --c)
		{
			flag = 0;
			if (map[r][c] == 'c') ret[r][c] = 0;
			else
			{
				for (i = c-1; i >= 0; --i)
				{
					if (map[r][i] == 'c')
					{
						ret[r][c] = c - i;
						flag = 1;
						break;
					}
				}
				if (!flag) ret[r][c] = -1;
			}
		}
	}
	print();
}
int main(void)
{
	freopen("input10709.txt", "r", stdin);
	register int r, c;
	scanf("%d %d", &H, &W);
	for (r = 0; r < H; ++r) scanf("%s", &map[r]);
	weather();
	return 0;
}