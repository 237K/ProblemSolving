//
//	OS Windows
//	2019.09.14
//
//	[Algorithm Problem Solving]
//
//	Codility	<BinaryGap>
//
//	ver.2
//

#include <stack>
int solution(int N) {
	register int rmd, cnt = 0, cur, ret = 0;
	stack<int> st;
	//  2������ ��ȯ
	while (N)
	{
		rmd = N % 2;
		st.push(rmd);
		N /= 2;
	}
	//  max gap ã��
	while (!st.empty())
	{
		cur = st.top();
		st.pop();
		//  1�� ������ ���� ����
		if (cur)
		{
			if (ret < cnt) ret = cnt;
			cnt = 0;
		}
		else cnt++;
	}
	return ret;
}