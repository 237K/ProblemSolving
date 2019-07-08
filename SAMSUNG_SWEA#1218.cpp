//
//	OS Windows
//	2019.07.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1218] (D4) °ýÈ£ Â¦Áþ±â
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	register int tc, i, ret;
	string input;
	stack<char> st;
	for (tc = 1; tc <= 10; ++tc)
	{
		while (!st.empty()) { st.pop(); }
		cin >> N;
		cin >> input;
		for (i = 0; i < N; ++i)
		{
			if (input[i] == '{' || input[i] == '[' || input[i] == '<' || input[i] == '(') st.push(input[i]);
			else
			{
				if (input[i] == '}' && st.top() == '{') st.pop();
				else if (input[i] == ']' && st.top() == '[') st.pop();
				else if (input[i] == '>' && st.top() == '<') st.pop();
				else if (input[i] == ')' && st.top() == '(') st.pop();
				else break;
			}
		}
		if (!st.empty()) ret = 0;
		else ret = 1;
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}