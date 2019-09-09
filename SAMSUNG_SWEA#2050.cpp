//
//	OS Windows
//	2019.09.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2050] (D1) 알파벳을 숫자로 변환
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	register int len, i;
	cin >> input;
	len = input.length();
	for (i = 0; i < len; ++i) cout << input[i] - 'A' + 1 << ' ';
	return 0;
}