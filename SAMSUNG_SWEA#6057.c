//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#6057> (D3) 그래프의 삼각형
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 51
int graph[MAX][MAX];
int N, M;
int search()
{
	register int i, j, k, ret = 0;
	for (i = 1; i <= N - 2; ++i)
	{
		for (j = i + 1; j <= N - 1; ++j)
		{
			if (graph[i][j])
			{
				for (k = j + 1; k <= N; ++k)
				{
					if (graph[i][k] && graph[j][k])	ret++;
				}
			}
		}
	}
	return ret;
}
int main(void)
{
	freopen("s_input6057.txt", "r", stdin);
	int T, v_start, v_end;
	register int test_case, m;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(graph, 0, sizeof(graph));
		scanf("%d %d", &N, &M);
		for (m = 0; m < M; ++m)
		{
			scanf("%d %d", &v_start, &v_end);
			graph[v_start][v_end] = 1;
			graph[v_end][v_start] = 1;
		}
		printf("#%d %d\n", test_case, search());
	}
	return 0;
}