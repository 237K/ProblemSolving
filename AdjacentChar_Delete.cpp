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
		while (1)
		{
			int cnt = 0;
			for (int i = 0; i < len - 1; ++i)
			{
				if (in[i] == in[i + 1])
				{
					in = in.substr(0, i) + in.substr(i + 2, len - 1);
					len -= 2;
					cnt++;
				}
			}
			if (cnt == 0 || len <= 1)
				break;
		}
		cout << "#" << test_case << ' ' << in << '\n';
	}
	return 0;
}