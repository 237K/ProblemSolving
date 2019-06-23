//
//	OS Windows
//	2019.05.30
//
//	[Algorithm Problem Solving]
//
//	Codility	<Tape Equilibrium>
//

int solution(vector<int> &A) {
	register int sum, left, right, ret, tmp, i, size;
	sum = left = right = tmp = 0; ret = 2147000000;
	size = A.size();
	for (i = 0; i < size; ++i) sum += A[i];
	for (i = 0; i < size - 1; ++i)
	{
		left += A[i];
		right = sum - left;
		tmp = left - right;
		if (tmp < 0) tmp *= -1;
		if (ret > tmp) ret = tmp;
	}
	return ret;
}