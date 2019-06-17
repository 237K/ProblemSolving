//
//	OS Windows
//	2019.06.09
//
//	[Algorithm Problem Solving]
//
//	Codility	<Missing Integer>
//

#include <algorithm>
int solution(vector<int>& A) {
	register int tmp = 0, idx = 0, sz, i;
	sort(A.begin(), A.end());
	sz = A.size();
	for (i = 0; i < sz; ++i)
	{
		if (A[i] < 0) continue;
		if (idx && A[i] - tmp > 1) return tmp + 1;
		if (A[i] == 1) idx = 1;
		tmp = A[i];
	}
	if (!idx) return 1;
	return tmp + 1;
}