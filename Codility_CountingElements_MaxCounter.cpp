//
//	OS Windows
//	2019.06.04
//
//	[Algorithm Problem Solving]
//
//	Codility	<Counting Elements>	Max Counter
//

vector<int> solution(int N, vector<int>& A) {
	register int i, sz, od, max_value = 0, tmp = 0;
	sz = A.size();
	vector<int> v(N, 0);
	for (i = 0; i < sz; ++i)
	{
		od = A[i];
		if (od > N) max_value = tmp;
		else
		{
			od--;
			if (v[od] < max_value) v[od] = max_value;
			if (tmp < ++v[od]) tmp = v[od];
		}
	}
	for (i = 0; i < N; ++i)
	{
		if (v[i] < max_value) v[i] = max_value;
	}
	return v;
}