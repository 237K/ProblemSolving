//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1346> 대표값2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int T = 5;
static vector<int> v(5, 0);
int main(int argc, char** argv)
{
	freopen("jinput1346.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, sum = 0;
	for (tc = 0; tc < T; ++tc)
	{
		cin >> v[tc];
		sum += v[tc];
	}
	sort(v.begin(), v.end());
	cout << sum / T << '\n' << v[2];
	return 0;
}