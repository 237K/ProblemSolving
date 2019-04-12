//
//	OS Windows
//	2019.04.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14501	Επ»η
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const static int MAX_DAY = 1500002;
static int period[MAX_DAY];
static int price[MAX_DAY];
static int DP[MAX_DAY];
static int N;
inline void init()
{
	(void)memset(period, 0, sizeof(period));
	(void)memset(price, 0, sizeof(price));
	(void)memset(DP, 0, sizeof(DP));
}
int main(int argc, char** argv)
{
	freopen("input14501.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	init();
	cin >> N;
	for (register int n = 1; n <= N; ++n)
		cin >> period[n] >> price[n];

	for (register int i = 1; i <= N; ++i)
	{
		DP[i + period[i]] = max(DP[i + period[i]], DP[i] + price[i]);
		DP[i + 1] = max(DP[i + 1], DP[i]);
	}
	cout << DP[N + 1];
	return 0;
}