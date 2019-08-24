//
//	OS Windows
//	2019.08.19
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1259] (D5) 금속막대
//

#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 20;
static int male[MAX], female[MAX], comb_idx[MAX], ret[MAX*2], check[MAX];
static int T, N, max_len, flag;
inline void comb(int cnt, int len)
{
	if (cnt > N) return;
	if (max_len)
	{
		flag = 1;
		return;
	}
	if (cnt == len)
	{
		//for (register int p = 0; p < cnt; ++p) cout << comb_idx[p] << ' ';
		//cout << "\n\n";
		flag = 1;
		for (register int c = 0; c < cnt-1; ++c)
		{
			if (female[comb_idx[c]] != male[comb_idx[c + 1]])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			register int idx = 0, r;
			max_len = cnt;
			for (r = 0; r < cnt; ++r)
			{
				ret[idx++] = male[comb_idx[r]];
				ret[idx++] = female[comb_idx[r]];
			}
		}
		return;
	}
	for (register int i = 0; i < N; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			comb_idx[cnt] = i;
			comb(cnt + 1, len);
			check[i] = 0;
		}
	}
}
inline void simul()
{
	register int len;
	max_len = 0;
	for (len = N; len >= 1; --len)
	{
		comb(0, len);
		if (flag) break;
	}
}
int main(int argc, char** argv)
{
	freopen("s_input1259.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, i, p;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(check, 0, sizeof(check)); max_len = 0;
		cin >> N;
		for (i = 0; i < N; ++i) cin >> male[i] >> female[i];
		simul();
		cout << "#" << tc << ' ';
		for (p = 0; p < max_len * 2; ++p) cout << ret[p] << ' ';
		cout << '\n';
	}
	return 0;
}