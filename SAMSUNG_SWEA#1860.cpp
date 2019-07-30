//
//	OS Windows
//	2019.07.30
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1860] (D3) Áø±âÀÇ ÃÖ°í±Þ ºØ¾î»§
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("s_input1860.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, M, K;
	register int tc, i, bb, ret;
	vector<int> V;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N >> M >> K;
		bb = 0; ret = 1; V.resize(N+1, 0);
		for (i = 1; i <= N; ++i) cin >> V[i];
		sort(V.begin() + 1, V.end());
		for (i = 1; i <= N; ++i)
		{
			bb = (V[i] / M) * K - i;
			if (bb < 0)
			{
				ret = 0;
				break;
			}
		}
		cout << "#" << tc << ' ';
		if (ret) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}