//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#6057> (D3) 그래프의 삼각형
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 51;
static int graph[MAX][MAX];
static int N, M;
inline int search()
{
	register int i, j, k, ret = 0;
	for (i = 1; i <= N-2; ++i)
	{
		for (j = i + 1; j <= N-1; ++j)
		{
			if (graph[i][j])
			{
				for (k = j + 1; k <= N; ++k)
				{
					if (graph[i][k] && graph[j][k])
					{
						ret++;
					}
				}
			}
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("s_input6057.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, m;
	int v_start, v_end;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(graph, 0, sizeof(graph));
		cin >> N >> M;
		for (m = 0; m < M; ++m)
		{
			cin >> v_start >> v_end;
			graph[v_start][v_end] = graph[v_end][v_start] = 1;
		}
		cout << "#" << test_case << ' ' << search() << '\n';
	}
	return 0;
}