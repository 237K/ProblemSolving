//
//	OS Windows
//	2019.06.17
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Stack and Queues>	(Fish)
//

#include <stack>
int solution(vector<int>& A, vector<int>& B) {
	stack<int> st;
	while (!st.empty()) { st.pop(); }
	int sz = A.size();
	register int i, cur, dead = 0;
	for (i = 0; i < sz; ++i)
	{
		if (!B[i] && st.empty()) continue;
		else if (!B[i])
		{
			while (!st.empty())
			{
				cur = st.top();
				if (A[cur] > A[i])
				{
					dead++;
					break;
				}
				else
				{
					dead++;
					st.pop();
				}
			}
		}
		else st.push(i);
	}
	return sz - dead;
}