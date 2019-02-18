//
//	OS Windows
//	2019.02.17
//
//	[Algorithm Problem Solving]
//
//	<�̷� Ż�� 2>
//	
//	1. �»��(1, 1)���� ����Ͽ� ���� N, ���� M ũ���� ���ڷ� �� �̷θ� Ż���ϰ��� ��
//	2. �̵��� ����, �Ʒ��θ� �� �� ����
//	3. �� ���ڿ��� ������ �־��� ������, Ż���ϸ鼭 ���� �� �ִ� �ִ������� ���
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const static int MAX = 3001;
const static int INF = -450000001;
int Map[MAX][MAX];
int Answer[MAX][MAX];
int N, M;

void Init()
{
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			Answer[r][c] = INF;
			Map[r][c] = 0;
		}
	}
}

void Escape()
{
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			if (r >= 2)
			{
				Answer[r][c] = max(Answer[r][c], Answer[r - 1][c] + Map[r][c]);
			}
			if (c >= 2)
			{
				Answer[r][c] = max(Answer[r][c], Answer[r][c - 1] + Map[r][c]);
			}
		}
	}
}

int main(void)
{
	int T;
	int test_case;
	freopen("testcase_Maze2.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		Init();
		for (int r = 1; r <= N; ++r)
		{
			for (int c = 1; c <= M; ++c)
			{
				scanf("%d", &Map[r][c]);
			}
		}
		Answer[1][1] = Map[1][1];
		Escape();
		printf("#%d %d\n", test_case, Answer[N][M]);
	}
	return 0;
}