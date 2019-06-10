//
//	OS Windows
//	2019.05.30
//
//	[Algorithm Problem Solving]
//
//	Codility	<Cyclic Rotation>
//

inline void right_shift(vector<int> &A)
{
	int size = A.size();
	if (!size) return;
	else
	{
		int tmp = A[size - 1];
		for (register int i = size - 1; i >= 0; --i)
			A[i] = A[i - 1];
		A[0] = tmp;
	}
}

vector<int> solution(vector<int> &A, int K) {
	while (K--) right_shift(A);
	return A;
}