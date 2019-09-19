//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15552 ºü¸¥ A+B
//

#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, A, B, tc;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> A >> B;
		cout << A + B << '\n';
	}
	return 0;
}