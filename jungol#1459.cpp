//
//	OS Windows
//	2020.03.31
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1459> 숫자고르기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 101;
static int arr[SZ], sel[SZ], N, nflag;
static vector<int> v2;
inline int compare(int n)
{
	register int i, flag = 1;
	sort(v2.begin(), v2.end());
	for (i = 0; i < n; ++i)
	{
		if (sel[i] != v2[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
inline void recur(int n, int cnt, int idx)
{
	if (nflag) return;
	if (cnt == n)
	{
		v2.clear();
		for (register int i = 0; i < n; ++i)
		{
			v2.push_back(arr[sel[i]]);
		}
		if (compare(n)) nflag = 1;
		return;
	}
	for (register int i = idx; i <= N; ++i)
	{
		sel[cnt] = i;
		recur(n, cnt + 1, i + 1);
	}
}
inline int simul()
{
	register int n, cnt;
		for (n = N; n > 0; n--)
		{
			nflag = 0;
			recur(n, 0, 1);
			if (nflag)
			{
				cnt = n;
				break;
			}
		}
	return cnt;
}
int main(void)
{
	freopen("jinput1459.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i, ret;
	v2.clear();
	for (i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		v2.push_back(arr[i]);
	}
	ret = simul();
	cout << ret << '\n';
	for (i = 0; i < ret; ++i)
		cout << v2[i] << '\n';
	return 0;
}