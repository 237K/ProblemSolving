//
//	OS Windows
//	2019.06.04
//
//	[Algorithm Problem Solving]
//
//	Codility	<Perm Check>
//

#include <algorithm>
int solution(vector<int> &A) {
	sort(A.begin(), A.end());
	int sz = A.size();
	for (register int i = 0; i < sz; ++i)
		if (A[i] != i + 1) return 0;
	return 1;
}