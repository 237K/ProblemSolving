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
#include <stack>
#include <vector>
using namespace std;

class Permutation
{
private:
	vector<int> *Graph;
	vector<int> Answer;
	stack<int> S;
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
		while (!S.empty()) { S.pop(); }
		Answer.clear();
		PrintV();
	}
	~Permutation()
	{
		delete[] Graph;
		delete[] Check;
	}
	void Go()
	{
		for (int i = 1; i <= N; ++i)
		{
			DFS(i);
		}
	}
	void DFS(int _index)
	{
		S.push(_index);
		Check[_index] = true;
		while (!S.empty())
		{
			int CurNode = S.top();
			cout << CurNode << ' ';
			S.pop();
			for (vector<int>::size_type i = 0; i < Graph->size(); ++i)
			{
				int NextNode = Graph[CurNode][i];
				if (Check[NextNode] == false)
				{
					S.push(NextNode);
					Check[NextNode] = true;
				}
			}
		}
		cout << endl;
		for (int i = 1; i <= N; ++i)
		{
			Check[i] = false;
		}
		//PrintAnswer();
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
	void PrintAnswer() const
	{
		for (vector<int>::size_type i = 0; i < Answer.size(); ++i)
		{
			cout << Answer[i] << ' ';
		}
		cout << endl;
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
		P[tc]->Go();
		cout << endl << endl;
	}

	for (int del = 1; del <= testcase; ++del)
	{
		delete P[del];
	}

	fin.close();
	return 0;
}