//
//	OS Windows
//	2019.12.30
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2441>	º° Âï±â - 4
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
char ret[SZ][SZ];
int main(void)
{
	freopen("input2441.txt", "r", stdin);
	int N, r, c;
	scanf("%d", &N);
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (r <= c) ret[r][c] = '*';
			else ret[r][c] = ' ';
		}
	}
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			printf("%c", ret[r][c]);
		}
		printf("\n");
	}
	return 0;
}