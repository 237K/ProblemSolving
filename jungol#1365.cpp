//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1365> 중간점수
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 10000;
static vector<int> v;
int main(int argc, char** argv)
{
	freopen("jinput1365.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, n, i;
	cin >> N;
	for (n = 0; n < N; ++n)
	{
		cin >> i;
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	cout << v[N/2];
	return 0;
}