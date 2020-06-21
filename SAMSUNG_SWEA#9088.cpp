//
//	OS Windows
//	2020.06.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#9088] (D4) 다이아몬드
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int T, N, K, in;
static vector<int> v;
int main(int argc, char** argv)
{
	freopen("sinput9088.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	register int tc, n, cnt, low, top;
	for (tc = 1; tc <= T; ++tc)
	{
		v.clear();
		cin >> N >> K;
		for (n = 0; n < N; ++n)
		{
			cin >> in;
			v.push_back(in);
		}
		sort(v.begin(), v.end());
		cnt = 1;
		top = 0;
		low = v[0];
		for (n = 1; n < N; ++n)
		{
			if (v[n] - low <= K)
			{
				cnt++;
			}
			else
			{
				if (top < cnt) top = cnt;
				low = v[n];
				cnt = 1;
			}
		}
		if (top < cnt) top = cnt;
		cout << "#" << tc << " " << top << "\n";
	}
	return 0;
}