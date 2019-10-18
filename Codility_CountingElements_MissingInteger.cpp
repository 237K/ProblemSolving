//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	Codility	<Counting Elements>	Missing Integer
//

#include <algorithm>
int solution(vector<int>& A) {
	register int tmp = 0, flag = 0, i, sz;
	sz = A.size();
	sort(A.begin(), A.end());
	if (A[sz - 1] < 1) return 1;
	for (i = 0; i < sz; ++i)
	{
		if (A[i] < 0) continue;
		if (A[i] == 1) flag = 1;
		if (flag && A[i] - tmp > 1) return tmp + 1;
		tmp = A[i];
	}
	if (!flag) return 1;
	return tmp + 1;
}
