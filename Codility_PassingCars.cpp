//
//	OS Windows
//	2019.06.10
//
//	[Algorithm Problem Solving]
//
//	Codility	<Passing Cars>
//

int solution(vector<int>& A) {
	int sz = A.size();
	register int i, cnt = 0, ret = 0;
	for (i = sz - 1; i >= 0; --i)
	{
		if (!A[i])
		{
			ret += cnt;
			if (ret > 1000000000)
			{
				ret = -1;
				break;
			}
		}
		else cnt++;
	}
	return ret;
}