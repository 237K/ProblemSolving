//
//	[ Algorithm problem solving ]
//	
//	OS Windows
//	2019.04.16
//
//	[Programmers] <L2 주식가격>
//
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int size = prices.size();
	register int i, j;
	for (i = 0; i < size - 1; ++i)
	{
		int time = 0;
		for (j = i + 1; j < size; ++j)
		{
			if (prices[i] <= prices[j])
				time++;
		}
		answer.push_back(time);
	}
 	answer.push_back(0);
	return answer;
}

int main(void)
{
	freopen("input#StockPrice.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> p;
	int SIZE = 0;
	cin >> SIZE;
	for (register int i = 0; i < SIZE; ++i)
	{
		int t = 0;
		cin >> t;
		p.push_back(t);
	}
	vector<int> a;
	a = solution(p);
	for (auto iter = a.begin(); iter != a.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	return 0;
}