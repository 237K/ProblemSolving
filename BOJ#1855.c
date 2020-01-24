//
//	OS Windows
//	2019.12.15
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #1855>	암호
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 201
#define SZ 21
char sent[MAX], ret[MAX];
char map[MAX][MAX];
int K;
int main(void)
{
	freopen("input1855.txt", "r", stdin);
	scanf("%d", &K);
	scanf("%s", &sent);
	register int i, j = 0, k = 0, l = 0;
	for (i = 0; sent[i]; ++i)
	{
		if (j >= K)
		{
			k++;
			j = K - 1;
		}
		else if (j < 0)
		{
			k++;
			j = 0;
		}
		if (!(k % 2))
		{
			map[k][j++] = sent[i];
		}
		else
		{
			map[k][j--] = sent[i];
		}
	}
	//for (i = 0; i <= k; ++i)
	//{
	//	for (j = 0; j < K; ++j)
	//	{
	//		printf("%c ", map[i][j]);
	//	}
	//	printf("\n\n");
	//}
	for (i = 0; i < K; ++i)
	{
		for (j = 0; j <= k; ++j)
		{
			ret[l++] = map[j][i];
		}
	}
	printf("%s", ret);
	return 0;
}