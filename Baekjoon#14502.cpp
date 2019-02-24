//
//	OS Windows
//	2019.02.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14502	¿¬±¸¼Ò
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
int N, M;
int **Map;
bool **Check;
vector<PII> Unaffected;
vector<PII> Start;
queue<PII> Q;
int CleanArea;

void Spread()
{
	for (vector<PII>::size_type i = 0; i < Start.size(); ++i)
	{
		Q.push(Start[i]);
	}
	while (!Q.empty())
	{
		PII Cur = Q.front();
		Q.pop();
		if (Cur.first - 1 >= 0 && Map[Cur.first - 1][Cur.second] == 0)
		{
			Map[Cur.first - 1][Cur.second] = 3;
			Q.push(PII(Cur.first - 1, Cur.second));
		}
		if (Cur.first + 1 < N && Map[Cur.first + 1][Cur.second] == 0)
		{
			Map[Cur.first + 1][Cur.second] = 3;
			Q.push(PII(Cur.first + 1, Cur.second));
		}
		if (Cur.second - 1 >= 0 && Map[Cur.first][Cur.second-1] == 0)
		{
			Map[Cur.first][Cur.second-1] = 3;
			Q.push(PII(Cur.first, Cur.second-1));
		}
		if (Cur.second + 1 < N && Map[Cur.first][Cur.second + 1] == 0)
		{
			Map[Cur.first][Cur.second+1] = 3;
			Q.push(PII(Cur.first, Cur.second+1));
		}
	}
}

int Search()
{
	int Clean = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if (Map[r][c] == 0)
				Clean++;
		}
	}
	return Clean;
}

void ClearMap()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if (Map[r][c] == 3)
				Map[r][c] = 0;
		}
	}
}

void PrintMap()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			cout << Map[r][c] << ' ';
		}
		cout << endl << endl;
	}
}

void Action(int depth)
{
	if (depth == 3)
	{
		Spread();
		//PrintMap();
		int Temp = Search();
		if (CleanArea < Temp)
			CleanArea = Temp;
		ClearMap();
		return;
	}
	else
	{
		for (vector<PII>::size_type i = 0; i < Unaffected.size(); ++i)
		{
			PII Cur = Unaffected[i];
			if (Check[Cur.first][Cur.second] == false)
			{
				Check[Cur.first][Cur.second] = true;
				Map[Cur.first][Cur.second] = 1;
				Action(depth + 1);
				Check[Cur.first][Cur.second] = false;
				Map[Cur.first][Cur.second] = 0;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("testcase_Baekjoon#14502.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		Map = new int*[N];
		Check = new bool*[N];
		for (int r = 0; r < N; ++r)
		{
			Map[r] = new int[M];
			Check[r] = new bool[M];
			for (int c = 0; c < M; ++c)
			{
				Map[r][c] = 0;
				Check[r][c] = false;
			}
		}
		Unaffected.clear();
		Start.clear();
		while (!Q.empty()) { Q.pop(); }
		CleanArea = 0;


		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				scanf("%d", &Map[r][c]);
				if (Map[r][c] == 0)
				{
					Unaffected.push_back(PII(r, c));
				}
				if (Map[r][c] == 2)
				{
					Start.push_back(PII(r, c));
				}
			}
		}
		Action(0);
		printf("#%d %d\n", test_case, CleanArea);

		for (int d = 0; d < N; ++d)
		{
			delete[] Map[d];
			delete[] Check[d];
		}
		delete[] Map;
		delete[] Check;
	}
	return 0;
}