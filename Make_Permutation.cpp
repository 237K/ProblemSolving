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
			Check[init] = false;
		}
		for (int r = 1; r <= _N; ++r)
		{
			for (int c = 1; c <= _N; ++c)
			{
				if (r != c)
				{
					Graph[r].push_back(c);
				}
			}
		}
		PrintV();
		while (!Q.empty()) { Q.pop(); }
	}
	~Permutation()
	{
		delete[] Check;
	}
	void DFS(int _index)
	{
		/*
		if (_depth == N+1)
		{
			cout << "{";
			while (!Q.empty())
			{
				cout << Q.front() << ' ';
				Q.pop();
			}
			cout << "}";
			return;
		}
		*/
		//else
		//{
			Q.push(_index);
			Check[_index] = true;
			for (vector<int>::size_type i = 0; i < Graph[_index].size(); ++i)
			{
				if (Check[Graph[_index][i]] == false)
				{
					//Q.push(Check[Graph[_index][i]]);
					//Check[Graph[_index][i]] = true;
					DFS(Graph[_index][i]);
					Check[Graph[_index][i]] = false;
				}
			}
			cout << "{";
			while (!Q.empty())
			{
				cout << Q.front() << ' ';
				Q.pop();
			}
			cout << "}";
			cout << endl;
		//}
	}
	void PrintV() const
	{
		for (int r = 1; r <= N; ++r)
		{
			cout << "[" << r << "] ";
			for (vector<int>::size_type c = 0; c < Graph[r].size(); ++c)
			{
				cout << Graph[r][c] << ' ';
			}
			cout << endl;
		}
	}
};

int main(void)
{
	Permutation *P[100];
	int testcase = 0;
	int _N = 0;
	ifstream fin("testcase_Permutation.txt");
	if (!fin.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		fin >> _N;
		P[tc] = new Permutation(_N);
		cout << "#" << tc << endl;
		P[tc]->DFS(1);
		cout << endl << endl;
	}

	for (int del = 1; del <= testcase; ++del)
	{
		delete P[del];
	}

	fin.close();
	return 0;
}