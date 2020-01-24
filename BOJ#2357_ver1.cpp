//
//	OS Windows
//	2019.12.26
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2357>	ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 100001;
static int arr[SZ], N, M, a, b;
static vector<int> v;
int main(int argc, char** argv)
{
	freopen("input2357.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int n, m;
	cin >> N >> M;
	for (n = 1; n <= N; ++n) cin >> arr[n];
	for (m = 0; m < M; ++m)
	{
		cin >> a >> b;
		v.clear();
		for (n = a; n <= b; ++n) v.push_back(arr[n]);
		sort(v.begin(), v.end());
		cout << v[0] << ' ' << v[b - a] << '\n';
	}
	return 0;
}