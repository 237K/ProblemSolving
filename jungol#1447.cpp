//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1447> 중간값들의 중간값찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 99;
static vector<int> table, mid;
static int N, in;
int main(void)
{
	freopen("jinput1447.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		table.clear();
		for (c = 0; c < N; ++c)
		{
			cin >> in;
			table.push_back(in);
		}
		sort(table.begin(), table.end());
		mid.push_back(table[N / 2]);
	}
	sort(mid.begin(), mid.end());
	cout << mid[N / 2];
	return 0;
}