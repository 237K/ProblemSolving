//
//	OS Windows
//	2019.10.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #9012 °ýÈ£
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input9012.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, tc, i, sz;
	string in, ret;
	stack<char> st;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		in.clear();
		while (!st.empty()) { st.pop(); }
		ret = "YES";
		cin >> in;
		sz = in.length();
		for (i = 0; i < sz; ++i)
		{
			if (in[i] == '(') st.push(in[i]);
			else
			{
				if (st.empty())
				{
					ret = "NO";
					break;
				}
				else st.pop();
			}
		}
		if (!st.empty()) ret = "NO";
		cout << ret << '\n';
	}
	return 0;
}