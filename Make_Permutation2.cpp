//
//  OS Windows
//  2019.02.12
//
//  [Algorithm Problem Solving]
//
//  <순열 출력하기>
//
//	1. N이 주어지는데, 가령 N = 3 이면 {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}의 순서로 출력
//
//	간단한 방식으로 구현해봄..
//

#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
private:
	int *Answer;
	bool *Check;
	int N;
public:
	Graph(int _N) : N(_N)
	{
		Answer = new int[N + 1];
		Check = new bool[N + 1];
		for (int i = 1; i <= N; ++i)
		{
			Answer[i] = 0;
			Check[i] = false;
		}
	}
	~Graph()
	{
		delete[] Answer;
		delete[] Check;
	}
	void DFS(int depth)
	{
		if (depth == N + 1)
		{
			for (int i = 1; i <= N; ++i)
			{
				cout << Answer[i] << ' ';
			}
			cout << endl;
		}
		else
		{
			for (int i = 1; i <= N; ++i)
			{
				if (Check[i] == false)
				{
					Check[i] = true;
					Answer[depth] = i;
					DFS(depth + 1);
					Check[i] = false;
				}
			}
		}
	}

};

int main(void)
{
	Graph *G[100];
	int testcase = 0, _N;
	ifstream fin("testcase_Permutation.txt");
	if (!fin.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		fin >> _N;
		cout << "#" << tc << endl;
		G[tc] = new Graph(_N);
		G[tc]->DFS(1);
		cout << endl;
	}

	fin.close();
	for (int del = 1; del <= testcase; ++del)
	{
		delete G[del];
	}
	return 0;
}