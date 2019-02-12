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

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

class Permutation
{
private:
	vector<int> Init;
	vector<int> *Graph;
	queue<int> Q;
	bool *Check;
	int N;
public:
	Permutation(int _N) : N(_N)
	{
		Graph = new vector<int>[_N + 1];
		Check = new bool[_N + 1];
		for (int init = 1; init <= _N; ++init)
		{
			Graph[init].clear();
			Init.push_back(init);
			Check[init] = false;
		}
		for (int r = 1; r <= _N; ++r)
		{
			for (int c = 1; c <= _N; ++c)
			{
				if (r != c)
				{
					Graph[r].push_back(c);
					Graph[c].push_back(r);
				}
			}
		}
		while (!Q.empty()) { Q.pop(); }
	}
	~Permutation()
	{
		delete[] Check;
	}
	void DFS(int _index, int _depth)
	{
		if (_depth == N)
		{
			cout << "{ ";
			while (!Q.empty())
			{
				cout << Q.front() << ' ';
				Q.pop();
			}
			cout << "} ";
		}
		else
		{
			if (Check[_index] == false && Graph[_index])
			{

			}
		}
		cout << endl << endl;
	}
};

int main(void)
{
	Permutation *P[100];
	int testcase = 0;
	int _N = 0;
	ifstream fin("testcase_Permutation.txt");

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		fin >> _N;
		P = new Permutation(_N);
	}

	for (int del = 1; del <= testcase; ++del)
	{
		delete P[del];
	}

	fin.close();
	return 0;
}