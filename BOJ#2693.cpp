//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2693>	N번째 큰 수
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int N = 10;
static vector<int> v;
static int T, in;
int main(int argc, char** argv)
{
	freopen("input2693.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	register int tc, n;
	for (tc = 0; tc < T; ++tc)
	{
		v.clear();
		for (n = 0; n < N; ++n)
		{
			cin >> in;
			v.push_back(in);
		}
		sort(v.begin(), v.end(), greater<int>());
		cout << v[2] << '\n';
	}
	return 0;
}