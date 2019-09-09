//
//	OS Windows
//	2019.09.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2063] (D1) 중간값 찾기
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, n;
	vector<int> v;
	cin >> N;
	v.resize(N);
	for (n = 0; n < N; ++n) cin >> v[n];
	sort(v.begin(), v.end());
	cout << v[N / 2];
	return 0;
}