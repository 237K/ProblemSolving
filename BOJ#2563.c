//
//	OS Windows
//	2019.08.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2563	»öÁ¾ÀÌ
//

#include <stdio.h>
#include <memory.h>
int map[101][101];
int main(void)
{
	freopen("input2563.txt", "r", stdin);
	(void)memset(map, 0, sizeof(map));
	int N, n, row, col, r, c, ret = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d", &col, &row);
		for (r = row; r < row + 10; ++r)
		{
			for (c = col; c < col + 10; ++c)
			{
				if (!map[r][c])
				{
					map[r][c] = 1;
					ret++;
				}
			}
		}
	}
	printf("%d", ret);
	return 0;
}