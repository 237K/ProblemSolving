//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6718] <희성이의 원근법> (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

inline int Cal(int n)
{
	if (n < 100)
		return 0;
	else if (n >= 100 && n < 1000)
		return 1;
	else if (n >= 1000 && n < 10000)
		return 2;
	else if (n >= 10000 && n < 100000)
		return 3;
	else if (n >= 100000 && n < 1000000)
		return 4;
	else
		return 5;
}

int main(int argc, char** argv)
{
	freopen("s_input6718.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num = 0;
		cin >> num;
		cout << "#" << test_case << ' ' << Cal(num) << '\n';
	}
	return 0;
}