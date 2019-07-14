//
//	OS Windows
//	2019.07.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3260] (D3) µÎ ¼öÀÇ µ¡¼À
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
static string A, B, tmp;
int main(int argc, char** argv)
{
	freopen("s_input4261.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, len, len1, len2;
	register int tc, n, idx;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> A >> B;
		len1 = A.length(); len2 = B.length();
		if (len1 < len2)
		{
			tmp = A;
			A = B;
			B = tmp;
			len = len2;
		}
		else len = len1;

	}
	return 0;
}