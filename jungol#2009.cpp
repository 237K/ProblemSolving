//
//	OS Windows
//	2020.05.23
//
//	[Algorithm Problem Solving]
//
//	[备泅] <jungol#2009> 老贸府
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	int T, N, C, n, cnt = 0;
	cin >> T >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> C;
		v.push_back(C);
	}
	sort(v.begin(), v.end());
	for (n = 0; n < N; ++n)
	{
		T -= v[n];
		if (T < 0) break;
		cnt++;
	}
	cout << cnt;
	return 0;
}