//
//	OS Windows
//	2019.06.19
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Stack and Queues>	(Nesting)
//

#include <stack>
int solution(string& S) {
	int sz = S.length();
	register int i;
	stack<char> st;
	for (i = 0; i < sz; ++i)
	{
		if (S[i] == '(') st.push('(');
		else
		{
			if (st.empty()) return 0;
			st.pop();
		}
	}
	if (!st.empty()) return 0;
	return 1;
}