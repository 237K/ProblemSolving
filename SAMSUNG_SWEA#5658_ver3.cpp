//
//	OS Windows
//	2019.08.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5658] (모의) 보물상자 비밀번호
//
//	ver.3
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
static int T, N, K, LEN;
static string input;
static vector<int> v;
inline int to10(string s)
{
	register int i, n, num, radix;
	n = s[LEN-1] - '0'; radix = LEN - 1;
	for (i = 0; i < LEN - 1; ++i)
	{
		char cur = s[i];
		if (cur >= '0' && cur <= '9') num = cur - '0';
		else num = cur - 'A' + 10;
		n += (int)(pow(16, radix--)) * num;
	}
	return n;
}
inline void rotate()
{
	register int i;
	char tmp = input[N - 1];
	for (i = N - 1; i > 0; --i) input[i] = input[i - 1];
	input[0] = tmp;
}
inline int simul()
{
	LEN = N / 4;
	register int i, j, tmp;
	for (i = 0; i < LEN; ++i)
	{
		for (j = 0; j < N; j += LEN)
		{
			string number = input.substr(j, LEN);
			tmp = to10(number);
			v.push_back(tmp);
		}
		rotate();
	}
	sort(v.begin(), v.end(), greater<int>());
	unique(v.begin(), v.end());
	return v[K-1];
}
int main(int argc, char** argv)
{
	freopen("s_input5658.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		input.clear(); v.clear();
		cin >> N >> K;
		cin >> input;
		cout << "#" << tc << ' ' << simul() << '\n';
	}
	return 0;
}