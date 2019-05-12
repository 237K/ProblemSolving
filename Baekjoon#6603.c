//
//	OS Windows
//	2019.05.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #6603	·Î¶Ç
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int S[13];
int check[13];
int k;
int p[13];

void print()
{
	for (register int i = 0; i < 6; ++i)
		printf("%d ", p[i]);
	printf("\n");
}
void dfs(int depth, int idx)
{
	if (depth == 6)
	{
		print();
		return;
	}
	else
	{
		for (register int i = idx; i < k; ++i)
		{
			p[depth] = S[i];
			dfs(depth + 1, i + 1);
		}
	}
}
int main(void)
{
	freopen("input6603.txt", "r", stdin);
	while (1)
	{
		scanf("%d", &k);
		if (!k) break;
		for (register int i = 0; i < k; ++i)
		{
			scanf("%d", &S[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}