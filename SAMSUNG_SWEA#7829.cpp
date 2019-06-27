//
//	OS Windows
//	2019.06.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7829] (D4) º¸¹°¿Õ ÅÂÇõ
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> v;
int main(int argc, char** argv)
{
	freopen("s_input7829.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	register int tc, n, i, ret;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		v.resize(N);
		for (n = 0; n < N; ++n)
		{
			cin >> v[n];
		}
		if (N == 1) ret = v[0] * v[0];
		else
		{
			sort(v.begin(), v.end());
			ret = v[0] * v[N - 1];
		}
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}