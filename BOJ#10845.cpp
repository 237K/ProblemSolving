//
//	OS Windows
//	2019.10.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10845 ť
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input10845.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, n, o;
	string order;
	queue<int> Q;
	while (!Q.empty()) { Q.pop(); }
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> o;
			Q.push(o);
		}
		else if (order == "pop")
		{
			if (Q.empty()) cout << "-1\n";
			else
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (order == "size") cout << Q.size() << '\n';
		else if (order == "empty") cout << Q.empty() << '\n';
		else if (order == "front")
		{
			if (Q.empty()) cout << "-1\n";
			else cout << Q.front() << '\n';
		}
		else
		{
			if (Q.empty()) cout << "-1\n";
			else cout << Q.back() << '\n';
		}
	}
	return 0;
}