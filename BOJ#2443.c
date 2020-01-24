//
//	OS Windows
//	2019.12.30
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2443>	º° Âï±â - 6
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 201
char ret[SZ][SZ];
int main(void)
{
	freopen("input2443.txt", "r", stdin);
	int N, r, i;
	scanf("%d", &N);
	for (r = 0; r < N; ++r)
		for (i = 0; i < 2 * N - 1; ++i)
			ret[r][i] = ' ';
	for (r = 0; r < N; ++r)
	{
		for (i = r; i < 2 * N - 1 - r; ++i)
		{
			ret[r][i] = '*';
		}
	}
	for (r = 0; r < N; ++r)
	{
		for (i = 0; i < 2 * N - 1; ++i)
		{
			printf("%c", ret[r][i]);
		}
		printf("\n");
	}
	return 0;
}