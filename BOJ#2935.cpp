//
//	OS Windows
//	2019.10.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2935	º“¿Ω
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
static string op[3], ret;
int main(void)
{
	freopen("input2935.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i, first, second, diff, d;
	for (i = 0; i < 3; ++i) op[i].clear();
	ret.clear();
	for (i = 0; i < 3; ++i) cin >> op[i];
	first = op[0].length();
	second = op[2].length();
	if (op[1][0] == '*')
	{
		diff = first + second - 1;
		ret.resize(diff, '0');
		ret[0] = '1';
	}
	else
	{
		diff = first - second;
		if (diff < 0) diff *= -1;
		if (first <= second) d = second;
		else d = first;
		ret.resize(d, '0');
		if (!diff)
		{
			ret[0] = '2';
		}
		else
		{
			ret[0] = '1';
			ret[diff] = '1';
		}
	}
	d = ret.length();
	for (i = 0; i < d; ++i) cout << ret[i];
	return 0;
}