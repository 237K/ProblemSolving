//
//	OS Windows
//	2019.06.28
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Maximum slice problem>	(MaxProfit)
//

int solution(vector<int>& A) {
	register int sz = A.size(), ret = 0, cur_min = 300000, i;
	for (i = 0; i < sz; ++i)
	{
		if (cur_min > A[i]) cur_min = A[i];
		if (ret < A[i] - cur_min) ret = A[i] - cur_min;
	}
	return ret;
}