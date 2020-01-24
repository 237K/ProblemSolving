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
using namespace std;
const static int SZ = 100001;
static int arr[SZ], N, M, a, b;
int main(int argc, char** argv)
{
	freopen("input2357.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int n, m, cur, low, high;
	cin >> N >> M;
	for (n = 1; n <= N; ++n) cin >> arr[n];
	for (m = 0; m < M; ++m)
	{
		low = 2147000000; high = 0;
		cin >> a >> b;
		for (n = a; n <= b; ++n)
		{
			cur = arr[n];
			if (low > cur) low = cur;
			if (high < cur) high = cur;
		}
		cout << low << ' ' << high << '\n';
	}
	return 0;
}