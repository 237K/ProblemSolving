//
//	OS Windows
//	2019.06.24
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4466] (D3) 최대 성적표 만들기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> v;
int main(int argc, char** argv)
{
	freopen("s_input4466.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, K;
	register int tc, n, i, ret;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N >> K;
		v.resize(N); ret = 0;
		for (n = 0; n < N; ++n)
		{
			cin >> v[n];
		}
		sort(v.begin(), v.end(), greater<int>());
		for (i = 0; i < K; ++i) ret += v[i];
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}