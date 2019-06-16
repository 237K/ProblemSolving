//
//	OS Windows
//	2019.06.04
//
//	[Algorithm Problem Solving]
//
//	Codility	<Perm Check>
//

static int check[100001] = { 0, };
int solution(int X, vector<int> &A) {
	register int cnt = 0;
	for (vector<int>::size_type i = 0; i < A.size(); ++i)
	{
		if (A[i] <= X && !check[A[i]])
		{
			check[A[i]] = 1;
			cnt++;
		}
		if (cnt == X) return i;
	}
	return -1;
}