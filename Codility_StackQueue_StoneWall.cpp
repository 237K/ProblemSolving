
//
//	OS Windows
//	2019.06.24
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Stack and Queues>	(StoneWall)
//

#include <stack>
int solution(vector<int>& H) {
	register int cnt = 0, i;
	int sz = H.size();
	stack<int> st;
	for (i = 0; i < sz; ++i)
	{
		while (!st.empty() && (st.top() > H[i])) st.pop();
		if (st.empty() || st.top() < H[i])
		{
			st.push(H[i]);
			cnt++;
		}
	}
	return cnt;
}