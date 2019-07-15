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
static string A, B, tmp, ret;
int main(int argc, char** argv)
{
	freopen("s_input4261.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, slen, llen, len1, len2;
	register int tc, n, idx, i, tmp, upper;
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
			llen = len2;
			slen = len1;
		}
		else
		{
			llen = len1;
			slen = len2;
		}
		tmp = upper = 0;
		while (1)
		{
			if (slen >= 0) tmp = upper + (A[llen - 1] - '0') + (B[slen - 1] - '0');
			else tmp = upper + (A[llen - 1] - '0');
			upper = tmp / 10;
			tmp %= 10;
			char cur = tmp + '0';
			ret.push_back(cur);
			llen--; slen--;
			if (llen < 0) break;
		}
		idx = ret.length() - 1;
		cout << "#" << tc << ' ';
		for (i = idx; i >= 0; --i) cout << ret[i];
		cout << '\n';
	}
	return 0;
}