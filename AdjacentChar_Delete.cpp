//
//	OS Windows
//	2019.03.25
//
//	[Algorithm Problem Solving]
//
//	<인접한 문자 제거하기>
//
//	1. 인접한 문자를 모두 제거하는 기능 구현
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("testcase_adjacentchar.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string in;
		cin >> in;
		int len = in.length();
		string::iterator iter_end;
		iter_end = in.begin() + len;
		while (adjacent_find(in.begin(), in.end()) != iter_end)
		{
			unique(in.begin(), in.end());
			iter_end = in.begin() + in.length();
		}
		cout << "#" << test_case << ' ' << in << '\n';
	}
	return 0;
}