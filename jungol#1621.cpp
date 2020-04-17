//
//	OS Windows
//	2020.04.16
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç] <jungol#1621> 6174
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 4;
const static int TARGET = 6174;
static vector<int> v(SZ, 0);
inline void dep(int n)
{
	register int i = 0;
	while (n)
	{
		v[i++] = n % 10;
		n /= 10;
	}
}
inline int cal()
{
	register int i, ret = 0;
	for (i = 0; i < SZ; ++i)
	{
		ret *= 10;
		ret += v[i];
	}
	return ret;
}
inline int simul(int n)
{
	register int high, low, diff = n, cnt = 0;
	while (1)
	{
		cnt++;
		dep(diff);
		sort(v.begin(), v.end(), greater<int>());
		high = cal();
		sort(v.begin(), v.end());
		low = cal();
		diff = high - low;
		if (diff == TARGET)
			break;
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("jinput1621.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << simul(N);
	return 0;
}