//
//	OS Windows
//	2019.06.04
//
//	[Algorithm Problem Solving]
//
//	Codility	<Max Counters>
//

vector<int> solution(int N, vector<int> &A) {
	register int max_value = 0, tmp_value = 0, i;
	vector<int> M;
	M.resize(N, 0);
	for (vector<int>::size_type n = 0; n < A.size(); ++n)
	{
		if (A[n] > N)
			max_value = tmp_value;
		else
		{
			if (M[A[n] - 1] < max_value)
				M[A[n] - 1] = max_value;
			M[A[n] - 1]++;
			if (tmp_value < M[A[n] - 1])
				tmp_value = M[A[n] - 1];
		}
	}
	for (i = 0; i < N; ++i)
	{
		if (max_value > M[i])
			M[i] = max_value;
	}
	return M;
}