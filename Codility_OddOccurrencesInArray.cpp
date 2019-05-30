//
//	OS Windows
//	2019.05.29
//
//	[Algorithm Problem Solving]
//
//	Codility	<Odd Occurrences In Array>
//

#include <algorithm>
int solution(vector<int> &A) {
	sort(A.begin(), A.end());
	register int cnt = 1;
	for (vector<int>::iterator iter = A.begin() + 1; iter != A.end(); ++iter)
	{
		if (*(iter - 1) == *iter) cnt++;
		else
		{
			if (cnt % 2) return *(iter - 1);
			else cnt = 1;
		}
	}
	return A.back();
}