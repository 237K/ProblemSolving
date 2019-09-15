//
//	OS Windows
//	2019.09.15
//
//	[Algorithm Problem Solving]
//
//	Codility	<Arrays>		Odd Occurrences In Array
//
//	ver.2
//


#include <algorithm>
int solution(vector<int>& A) {
	register int i, sz, cnt, ret;
	sz = A.size();
	sort(A.begin(), A.end());
	cnt = 1; ret = A[0];
	for (i = 1; i < sz; ++i)
	{
		if (A[i] == A[i - 1]) cnt++;
		else
		{
			if (cnt % 2)
			{
				ret = A[i - 1];
				break;
			}
			else
			{
				cnt = 1;
				if (i == sz - 1) ret = A[sz - 1];
			}
		}
	}
	return ret;
}