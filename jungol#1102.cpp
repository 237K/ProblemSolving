//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1102> 스택
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char** argv)
{
	freopen("jinput1102.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> S;
	int n, N, num;
	char order;
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> order;
		if (order == 'i')
		{
			cin >> num;
			S.push(num);
		}
		else if (order == 'o')
		{
			if (S.empty())
			{
				cout << "empty\n";
				continue;
			}
			cout << S.top() << "\n";
			S.pop();
		}
		else
		{
			cout << S.size()<<'\n';
		}
	}
	return 0;
}