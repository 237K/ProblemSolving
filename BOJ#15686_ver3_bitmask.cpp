//
//	OS Windows
//	2019.09.04
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15686	ġŲ ���
//
//	ver.3 bitmask
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 51;
const static int MAX = 13;
static pii house[100], store[13];
static int sel_idx[13];
static int N, M, num_house, num_store, tmp;

inline int absolute(int a)
{
	if (a < 0) a *= -1;
	return a;
}
inline int cal_dist()
{
	register int i, j, chr, chc, ci, ccr, ccc, tmpr, tmpc, min_dist, sum = 0;
	for (i = 0; i < num_house; ++i)
	{
		min_dist = 2147000000;
		chr = house[i].first;
		chc = house[i].second;
		for (j = 0; j < M; ++j)
		{
			ci = sel_idx[j];
			ccr = store[ci].first;
			ccc = store[ci].second;
			tmpr = absolute(chr - ccr); tmpc = absolute(chc - ccc);
			if (min_dist > tmpr + tmpc) min_dist = tmpr + tmpc;
		}
		sum += min_dist;
	}
	return sum;
}
inline int simul()
{
	register int mask, flag, cnt, ins, cur, ret = 2147000000;
	for (mask = 0; mask < (1 << num_store); ++mask)
	{
		cnt = 0;
		for (flag = 0; flag < num_store; ++flag)
		{
			if ((mask & (1 << flag))) cnt++;
		}
		if (cnt == M)
		{
			ins = 0;
			for (flag = 0; flag < num_store; ++flag)
			{
				if ((mask & (1 << flag))) sel_idx[ins++] = flag;
			}
			cur = cal_dist();
			if (ret > cur) ret = cur;
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	freopen("input15686.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	num_store = num_house = 0;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> tmp;
			if (tmp == 1) house[num_house++] = { r, c };
			else if (tmp == 2) store[num_store++] = { r, c };
		}
	}
	cout << simul();
	return 0;
}