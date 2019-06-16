//
//	OS Windows
//	2019.06.10
//
//	[Algorithm Problem Solving]
//
//	Codility	<Min Avg Two Slice>
//
//	**********************************************
//	1. 두 수의 평균은 항상 두 수 중 작은 값보다 크다
//	2. 두 평균값의 평균은 두 평균값 중 작은 값보다 크다.
//	3. 모든 슬라이스는 2개의 원소로 이루어진 슬라이스, 3개의 원소로 이루어진 슬라이스로 표현된다.
//	   (4개의 원소를 가진 슬라이스는 2개의 원소로 이루어진 슬라이스들의 평균값들에 대한 평균값 이므로
//		4개의 원소를 가진 슬라이스의 평균값은 2개의 원소로 이루어진 슬라이스들의 평균값 중 작은 값보다 항상 크다)
//

int solution(vector<int>& A) {
	int sz = A.size();
	register int i, min_idx = 0;
	double tmp = 0.0, min_value = 2147000000.0;
	for (i = 0; i < sz - 1; ++i)
	{
		tmp = (double)(A[i] + A[i + 1]) / (double)2.0;
		if (min_value > tmp)
		{
			min_value = tmp;
			min_idx = i;
		}
		if (i + 2 < sz)
		{
			tmp = (double)(A[i] + A[i + 1] + A[i + 2]) / (double)3.0;
			if (min_value > tmp)
			{
				min_value = tmp;
				min_idx = i;
			}
		}
	}
	return min_idx;
}