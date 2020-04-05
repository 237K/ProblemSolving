//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1445> 순환
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
static string str;
static int len;
inline void shift()
{
	register int i;
	char tmp = str[len - 1];
	for (i = len - 1; i > 0; --i)
	{
		str[i] = str[i - 1];
	}
	str[0] = tmp;
	cout << str << '\n';
}
int main(int argc, char** argv)
{
	freopen("jinput1445.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1)
	{
		cin >> str;
		if (str[0] == '0') break;
		len = str.length();
		cout << str<<'\n';
		for (register int i = 0; i < len-1; ++i)
			shift();
	}
	return 0;
}