//
//	OS Windows
//	2019.04.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7193] <승현이의 수학공부> (D3)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	freopen("s_input7193.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, len;
	register int test_case, X, i;
	string in;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		X = 0; in.clear();
		cin >> in;
		len = in.length();
		for (i = 0; i < len; ++i)
			X += in[i] - '0';
		cout << "#" << test_case << ' ' << X % (N - 1) << '\n';
	}
	return 0;
}