//
//	OS Windows
//	2020.04.19
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç] <jungol#1697> queue
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> Q;
	char order;
	int N, n, a;
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> order;
		if (order == 'i')
		{
			cin >> a;
			Q.push(a);
		}
		else if (order == 'o')
		{
			if (Q.empty()) cout << "empty\n";
			else
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else
		{
			cout << Q.size() << '\n';
		}
	}
	return 0;
}