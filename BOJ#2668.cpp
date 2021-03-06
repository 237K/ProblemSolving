//
//	OS Windows
//	2019.11.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2668	숫자고르기
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int MAX = 101;
static vector<int> upper, lower;
static int arr[MAX], ret[MAX];
static int N, flag, ret_num;
inline void dfs(int cnt, int idx, int n)
{
	if (cnt == n)
	{
		for (register int i = 0; i < cnt; ++i)
		{
			int cur = upper[i]-1;
			lower[i] = arr[cur];
		}
		sort(lower.begin(), lower.end());
		flag = 1;
		for (register int i = 0; i < n; ++i)
		{
			if (upper[i] != lower[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			ret_num = n;
			for (register int i = 0; i < n; ++i)
			{
				ret[i] = lower[i];
			}
		}
		return;
	}
	for (register int j = idx; j <= N; ++j)
	{
		upper[cnt] = j;
		dfs(cnt + 1, j + 1, n);
	}
}
inline void simul()
{
	register int i;
	for (i = N; i > 0; --i)
	{
		dfs(0, 1, i);
		if (ret_num) break;
	}
	cout << ret_num << '\n';
	for (i = 0; i < ret_num; ++i) cout << ret[i] << '\n';
}
int main(int argc, char** argv)
{
	freopen("input2668.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int n;
	ret_num = 0;
	cin >> N;
	upper.resize(N, 0);
	lower.resize(N, 0);
	for (n = 0; n < N; ++n)
	{
		cin >> arr[n];
	}
	simul();
	return 0;
}