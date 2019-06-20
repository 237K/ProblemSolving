//
//	OS Windows
//	2019.06.15
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Sorting>	(Number OF Disc Intersections)
//

#include <algorithm>
const static int MAX = 100000;
vector<long long> lower, upper;
int solution(vector<int>& A) {
	int sz = A.size();
	lower.resize(sz); upper.resize(sz);
	register int i, j = 0, ret = 0;
	for (i = 0; i < sz; ++i)
	{
		lower[i] = (long long)(i)-(long long)(A[i]);
		upper[i] = (long long)(i)+(long long)(A[i]);
	}
	sort(lower.begin(), lower.end());
	sort(upper.begin(), upper.end());
	for (i = 0; i < sz; ++i)
	{
		while (1)
		{
			if (j >= sz || lower[j] > upper[i]) break;
			ret += j;
			ret -= i;
			j++;
		}
	}
	if (ret > 10000000) ret = -1;
	return ret;
}