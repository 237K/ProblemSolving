//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6900] <ÁÖÇõÀÌÀÇ º¹±Ç ´çÃ·> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
	int test_case;
	int T;
	int N, M;
	int **My;
	char **Input;
	int *Money;
	int Answer;
	bool Flag;
	freopen("s_input6900.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0; M = 0; Flag = true; Answer = 0;
		scanf("%d %d", &N, &M);
		My = new int*[M];
		Input = new char*[N];
		Money = new int[N];
		for (int i = 0; i < N; ++i)
		{
			Input[i] = new char[9];
			scanf("%9s %d", Input[i], &Money[i]);
		}
		for (int i = 0; i < M; ++i)
		{
			My[i] = new int[8];
			for (int j = 0; j < 8; ++j)
			{
				scanf("%1d", &My[i][j]);
			}
		}
		for (int n = 0; n < N; ++n)
		{
			for (int m = 0; m < M; ++m)
			{
				Flag = true;
				for (int i = 0; i < 8; ++i)
				{
					if (Input[m][i] == '*')
						continue;
					else
					{
						char ch[2];
						int idx = i;
						ch[0] = Input[m][i];
						if (atoi(ch) != My[n][idx])
						{
							Flag = false;
							continue;
						}
					}
				}
				if (Flag)
				{
					Answer += Money[m];
				}
			}
		}
		printf("#%d %d\n", test_case, Answer);
		for (int i = 0; i < N; ++i)
		{
			delete[] Input[i];
		}
		delete[] Input;
		for (int i = 0; i < M; ++i)
		{
			delete[] My[i];
		}
		delete[] My;
		delete[] Money;
	}
	return 0;
}