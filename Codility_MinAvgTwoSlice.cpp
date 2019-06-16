//
//	OS Windows
//	2019.06.10
//
//	[Algorithm Problem Solving]
//
//	Codility	<Min Avg Two Slice>
//
//	**********************************************
//	1. �� ���� ����� �׻� �� �� �� ���� ������ ũ��
//	2. �� ��հ��� ����� �� ��հ� �� ���� ������ ũ��.
//	3. ��� �����̽��� 2���� ���ҷ� �̷���� �����̽�, 3���� ���ҷ� �̷���� �����̽��� ǥ���ȴ�.
//	   (4���� ���Ҹ� ���� �����̽��� 2���� ���ҷ� �̷���� �����̽����� ��հ��鿡 ���� ��հ� �̹Ƿ�
//		4���� ���Ҹ� ���� �����̽��� ��հ��� 2���� ���ҷ� �̷���� �����̽����� ��հ� �� ���� ������ �׻� ũ��)
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