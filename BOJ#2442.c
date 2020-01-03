//
//	OS Windows
//	2019.12.30
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2442>	º° Âï±â - 5
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 201
char ret[SZ][SZ];
int main(void)
{
	freopen("input2442.txt", "r", stdin);
	int N, r, c;
	scanf("%d", &N);
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < 2 * N - 1; ++c)
		{
			if (c < N - r - 1 || c > N + r - 1) ret[r][c] = ' ';
			else ret[r][c] = '*';
			printf("%c", ret[r][c]);
		}
		printf("\n");
	}
	return 0;
}