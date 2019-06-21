//
//	OS Windows
//	2019.06.17
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Stack and Queues>	(Brackets)
//

#include <stack>
int solution(string& S) {
	stack<char> st;
	while (!st.empty()) { st.pop(); }
	int sz = S.length();
	register int i;
	for (i = 0; i < sz; ++i)
	{
		if (st.empty() && (S[i] == ')' || S[i] == ']' || S[i] == '}')) return 0;
		if (S[i] == '(' || S[i] == '[' || S[i] == '{') st.push(S[i]);
		else
		{
			if (S[i] == ')')
			{
				if (st.top() == '(')
				{
					st.pop();
					continue;
				}
				else return 0;
			}
			if (S[i] == ']')
			{
				if (st.top() == '[')
				{
					st.pop();
					continue;
				}
				else return 0;
			}
			if (S[i] == '}')
			{
				if (st.top() == '{')
				{
					st.pop();
					continue;
				}
				else return 0;
			}
		}
	}
	if (!st.empty()) return 0;
	return 1;
}