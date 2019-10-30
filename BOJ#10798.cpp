//
//	OS Windows
//	2019.10.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10798	세로읽기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const static int SZ = 5;
static string str[SZ];
inline void init()
{
	for (register int i = 0; i < SZ; ++i) str[i].clear();
}
int main(int argc, char** argv)
{
	freopen("input10798.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	register int i, j, len, max_len = 0;
	for (i = 0; i < SZ; ++i)
	{
		cin >> str[i];
		len = str[i].length();
		if (max_len < len) max_len = len;
	}
	for (j = 0; j < max_len; ++j)
	{
		for (i = 0; i < SZ; ++i)
		{
			len = str[i].length();
			if (len <= j) continue;
			cout << str[i][j];
		}
	}
	return 0;
}