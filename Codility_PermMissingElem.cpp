//
//	OS Windows
//	2019.05.30
//
//	[Algorithm Problem Solving]
//
//	Codility	<Perm Missing Elem>
//

#include <algorithm>
int solution(vector<int> &A) {
	int size = A.size(), ret = 0;
	if (!size) return 1;
	else
	{
		sort(A.begin(), A.end());
		for (register int i = 0; i < size; ++i)
		{
			if (A[i] != i + 1)
			{
				ret = i + 1;
				break;
			}
		}
		if (!ret) ret = size + 1;
	}
	return ret;
}