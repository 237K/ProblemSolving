//
//	OS Windows
//	2019.05.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1094	¸·´ë±â
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stick[7] = { 64, 32, 16, 8, 4, 2, 1 };
int check[7] = { 0, };
int X, result;

void dfs(int depth, int len)
{
	if (len == X)
	{
		if(result > depth)	result = depth;
		return;
	}
	if (len > X) return;
	else
	{
		for (register int i = 0; i < 8; ++i)
		{
			if (!check[i])
			{
				check[i] = 1;
				dfs(depth + 1, len + stick[i]);
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input1094.txt", "r", stdin);
	result = 2147000000;
	scanf("%d", &X);
	dfs(0, 0);
	printf("%d\n", result);
	return 0;
}