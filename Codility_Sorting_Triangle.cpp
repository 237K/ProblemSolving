//
//	OS Windows
//	2019.06.13
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Sorting>	(Triangle)
//

#include <algorithm>
int solution(vector<int>& A) {
	sort(A.begin(), A.end());
	int sz = A.size();
	register int i;
	for (i = 2; i < sz; ++i)
	{
		if (A[i - 2] <= 0) continue;
		if (A[i - 1] >= 2147483647 || A[i - 1] + A[i - 2] >= 2147483647 || (A[i]) < (A[i - 1] + A[i - 2])) return 1;
	}
	return 0;
}