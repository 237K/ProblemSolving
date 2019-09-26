//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	Codility	<Arrays>		Cyclic Rotation
//

vector<int> solution(vector<int>& A, int K)
{
	register int i, idx, sz;
	vector<int> B;
	sz = A.size();
	B.resize(sz);
	for (i = 0; i < sz; ++i)
	{
		idx = (i + K) % sz;
		B[idx] = A[i];
	}
	return B;
}