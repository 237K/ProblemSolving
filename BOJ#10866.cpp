//
//	OS Windows
//	2019.10.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10866 µ¦
//

#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input10866.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, n, o;
	string order;
	deque<int> dq;
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> order;
		if (order == "push_front")
		{
			cin >> o;
			dq.push_front(o);
		}
		else if (order == "push_back")
		{
			cin >> o;
			dq.push_back(o);
		}
		else if (order == "pop_front")
		{
			if (dq.empty()) cout << "-1\n";
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (order == "pop_back")
		{
			if (dq.empty()) cout << "-1\n";
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (order == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (order == "empty")
		{
			cout << dq.empty() << '\n';
		}
		else if (order == "front")
		{
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << '\n';
		}
		else
		{
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << '\n';
		}
	}
	return 0;
}