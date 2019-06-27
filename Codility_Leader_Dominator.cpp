//
//	OS Windows
//	2019.06.27
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Leader>	(Dominator)
//

#include <stack>
int solution(vector<int>& A) {
	stack<int> st;
	int sz = A.size();
	register int i, cnt = 0, ret = 0;
	for (i = 0; i < sz; ++i)
	{
		if (st.empty()) st.push(A[i]);
		else if (st.top() == A[i]) st.push(A[i]);
		else st.pop();
	}
	if (st.empty()) return -1;
	else
	{
		for (i = 0; i < sz; ++i)
		{
			if (st.top() == A[i])
			{
				ret = i;
				cnt++;
			}
		}
		if (cnt <= sz / 2) ret = -1;
	}
	return ret;
}