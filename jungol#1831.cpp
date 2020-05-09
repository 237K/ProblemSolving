//
//	OS Windows
//	2020.05.07
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1831> 품평회 행사
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 10000;
static pii d[SZ];
static vector<pii> v;
static int sel[SZ], N, T, L, F;
inline int check()
{
	register int i, sz, flag, cnt;
	sz = v.size();
	sort(v.begin(), v.end());
	cnt = 0;
	flag = 1;
	for (i = 0; i < sz; ++i)
	{
		if (cnt > v[i].first)
		{
			flag = 0;
			break;
		}
		cnt = v[i].first + v[i].second - 1;
	}
	return flag;
}
inline void comb(int cnt, int idx, int Z)
{
	if (F) return;
	else
	{
		if (cnt == Z)
		{
			v.clear();
			for (register int i = 0; i < cnt; ++i)
				v.push_back({ d[sel[i]] });
			if (check())
			{
				F = 1;
			}
			return;
		}
		else
		{
			for (register int j = idx; j < N; ++j)
			{
				sel[cnt] = j;
				comb(cnt + 1, j + 1, Z);
			}
		}
	}
}
inline int simul()
{
	register int z, ret;
	F = 0;
	ret = 1;
	for (z = N; z > 1; z--)
	{
		comb(0, 0, z);
		if (F)
		{
			ret = z;
			break;
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("jinput1831.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int n;
	for (n = 0; n < N; ++n)
	{
		cin >> T >> L;
		d[n] = { T, L };
	}
	cout << simul();
	return 0;
}