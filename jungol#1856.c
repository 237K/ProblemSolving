//
//	OS Windows
//	2020.05.12
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1856> 숫자사각형2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
int N, M, arr[SZ][SZ];
void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			printf("%d ", arr[r][c]);
		}
		printf("\n");
	}
}
int main(void)
{
	freopen("jinput1856.txt", "r", stdin);
	register int i = 1 , r, c;
	scanf("%d %d", &N, &M);
	for (r = 0; r < N; ++r)
	{
		if (!(r % 2))
		{
			for (c = 0; c < M; ++c)
			{
				arr[r][c] = i++;
			}
		}
		else
		{
			for (c = M - 1; c >= 0; --c)
			{
				arr[r][c] = i++;
			}
		}
	}
	print();
	return 0;
}