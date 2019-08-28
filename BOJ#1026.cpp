//
//	OS Windows
//	2019.08.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1026	º¸¹°
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("s_input1026.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, n, ret;
	vector<int> A, B;
	cin >> N;
	A.resize(N); B.resize(N);
	for (n = 0; n < N; ++n) cin >> A[n];
	for (n = 0; n < N; ++n) cin >> B[n];
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end());
	ret = 0;
	for (n = 0; n < N; ++n) ret += A[n] * B[n];
	cout << ret;
	return 0;
}