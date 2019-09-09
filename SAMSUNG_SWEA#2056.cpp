//
//	OS Windows
//	2019.09.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2056] (D1) 연월일 달력
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
static int check[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
inline int str_to_int(string str)
{
	register int value = 0, i, len;
	len = str.length();
	for (i = 0; i < len; ++i)
	{
		value *= 10;
		value += str[i] - '0';
	}
	return value;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, y, m, d;
	string input, year, month, day;
	register int tc;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		input.clear();
		cin >> input;
		year = input.substr(0, 4);
		month = input.substr(4, 2);
		day = input.substr(6, 2);
		y = str_to_int(year);
		m = str_to_int(month);
		d = str_to_int(day);
		cout << "#" << tc << ' ';
		if (m < 1 || m > 12 || d < 1 || d > check[m]) cout << "-1\n";
		else cout << year << '/' << month << '/' << day << "\n";
	}
	return 0;
}