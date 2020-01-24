//
//	OS Windows
//	2019.10.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15650	N°ú M 2
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 8;
static vector<int> v;
static int N, M;
inline void print()
{
	register int i;
	for (i = 0; i < M; ++i) cout << v[i] << ' ';
	cout << "\n";
}
inline void recur(int cnt, int idx)
{
	if (cnt == M)
	{
		sort(v.begin(), v.end());
		print();
		return;
	}
	for (register int i = idx; i <= N; ++i)
	{
		v[cnt] = i;
		recur(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input15650.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	v.resize(M);
	recur(0, 1);
	return 0;
}