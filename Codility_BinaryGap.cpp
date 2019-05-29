//
//	OS Windows
//	2019.05.28
//
//	[Algorithm Problem Solving]
//
//	Codility	<BinaryGap>
//
#include <iostream>
using namespace std;

int solution(int N) {
	register int rmd, longest = 0, idx = 0, tmp = -1;
	while (1)
	{
		rmd = N % 2;
		if (rmd)
		{
			if (idx && tmp >= 0 && longest < idx - tmp - 1) longest = idx - tmp - 1;
			tmp = idx;
		}
		if (N) N /= 2, idx++;
		else break;
	}
	return longest;
}

int main(void)
{
	freopen("c_inputBG.txt", "r", stdin);
	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		cout << "#" << tc << ' ' << solution(N) << '\n';
	}
	return 0;
}