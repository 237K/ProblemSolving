//
//	OS Windows
//	2019.10.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10828 Ω∫≈√
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
	freopen("input10828.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, n, o, sz = 0;
	string order;
	stack<int> st;
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		order.clear();
		cin >> order;
		if (order == "push")
		{
			cin >> o;
			st.push(o);
			sz++;
		}
		else if (order == "pop")
		{
			if (!sz) cout << "-1" << '\n';
			else
			{
				cout << st.top() << '\n';
				st.pop();
				sz--;
			}
		}
		else if (order == "size")
		{
			cout << sz << '\n';
		}
		else if (order == "empty")
		{
			int p = 0;
			if (!sz) p = 1;
			cout << p << '\n';
		}
		else if (order == "top")
		{
			if (!sz) cout << "-1" << '\n';
			else cout << st.top() << '\n';
		}
	}
	return 0;
}