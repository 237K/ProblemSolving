//
//	OS Windows
//	2019.06.27
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2005] (D2) ÆÄ½ºÄ®ÀÇ »ï°¢Çü
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
static int pt[11][11];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	register int tc, n, r, c;
	for (n = 1; n <= 10; ++n) pt[n][1] = pt[n][n] = 1;
	for (r = 2; r <= 10; ++r)
	{
		for (c = 1; c <= 10; ++c)
			pt[r][c] = pt[r - 1][c - 1] + pt[r - 1][c];
	}
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		cout << "#" << tc << '\n';
		for (r = 1; r <= N; ++r)
		{
			for (c = 1; c <= 10; ++c)
				if (pt[r][c]) cout << pt[r][c] << ' ';
			cout << '\n';
		}
	}
	return 0;
}