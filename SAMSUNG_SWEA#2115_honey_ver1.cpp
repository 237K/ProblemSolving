//
//	OS Windows
//	2019.04.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2115> (¸ðÀÇ) ¹ú²ÜÃ¤Ãë
//	
//	ver1.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
const static int SIZE = 10;
const static int MAX_M = 5;

static int N, M, C;
static int map[SIZE][SIZE];
static int check[SIZE][SIZE];
static vector<int> bee_A;
static vector<int> bee_B;
static int result_bee_A;
static int result_bee_B;
static int result;
static int max_profit;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, 0, sizeof(check));
	bee_A.clear();
	bee_B.clear();
	result = 0;
	max_profit = 0;
}
/*
inline void print(vector<int> v)
{
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << '\n';
}
*/
inline void calculate(vector<int>& bee, int count, int capa, int profit)
{
	if (capa > C)
		return;
	result = max(result, profit);
	if (count >= M)
		return;
	calculate(bee, count + 1, capa + bee[count], profit + bee[count] * bee[count]);
	calculate(bee, count + 1, capa, profit);
}

inline void select()
{
	for (int ar = 0; ar < N; ++ar)
	{
		for (int ac = 0; ac + M - 1 < N; ++ac)
		{
			for (int am = 0; am < M; ++am)
			{
				bee_A.push_back(map[ar][ac + am]);
				check[ar][ac + am]++;
			}
			//cout << "bee A : "; print(bee_A);
			calculate(bee_A, 0, 0, 0);
			result_bee_A = result;
			result = 0;
			for (int br = ar+1; br < N; ++br)
			{
				for (int bc = 0; bc < N - M + 1; ++bc)
				{
					for (int bm = 0; bm < M; ++bm)
					{
						if (check[br][bc + bm])
							continue;
						else
						{
							bee_B.push_back(map[br][bc + bm]);
						}
					}
					//cout << "bee B : "; print(bee_B);
					calculate(bee_B, 0, 0, 0);
					result_bee_B = result;
					result = 0;
					max_profit = max(max_profit, result_bee_A + result_bee_B);
					bee_B.clear();
				}
			}
			//cout << "Result : "<<max_profit<<"\n\n";
			bee_A.clear();
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input2115.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> C;
		init();
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
			}
		}
		select();
		cout << "#" << test_case << ' ' << max_profit << '\n';
	}
	return 0;
}