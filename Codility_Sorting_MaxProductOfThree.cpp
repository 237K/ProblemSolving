//
//	OS Windows
//	2019.06.13
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Sorting>	(Max Product of Three)
//

#include <algorithm>
int solution(vector<int>& A) {
	int ret = 0, sz = A.size(), tmp1, tmp2;
	if (sz == 3) ret = A[0] * A[1] * A[2];
	else if (sz > 3)
	{
		sort(A.begin(), A.end(), greater<int>());
		tmp1 = A[0] * A[1] * A[2];
		tmp2 = A[0] * A[sz - 1] * A[sz - 2];
		ret = tmp1 > tmp2 ? tmp1 : tmp2;
	}
	return ret;
}