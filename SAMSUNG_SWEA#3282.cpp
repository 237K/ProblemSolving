//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3282] (D3) 0/1 Knapsack
//

#include <iostream>
using namespace std;
const static int MAX = 100;
static int V[MAX], C[MAX];
static int T, N, K, ret;
inline void recur(int cnt, int idx, int c, int v)
{
	if (cnt >= N) return;
	if (v > K) return;
	if (ret < c) ret = c;
	for (register int i = idx; i < N; ++i)
	{
		if (V[i] > K) continue;
		recur(cnt + 1, i + 1, c + C[i], v + V[i]);
	}
}
int main(int argc, char** argv)
{
	freopen("s_input3282.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, n;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		ret = 0;
		cin >> N >> K;
		for (n = 0; n < N; ++n)
		{
			cin >> V[n] >> C[n];
		}
		recur(0, 0, 0, 0);
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}