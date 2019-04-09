//
//	OS Windows
//	2019.04.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #6064	Ä«À×´Þ·Â
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
static int M, N, x, y;
inline int cal()
{
	for (register int i = x; i < M*N; i += M)
	{
		if (y == N)
		{
			if (!(i%N))
				return i;
		}
		else
		{
			if (i % N == y)
				return i;
		}
	}
	return -1;
}
int main(int argc, char** argv)
{
	freopen("input6064.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> M >> N >> x >> y;
		cout << cal() << '\n';
	}
	return 0;
}