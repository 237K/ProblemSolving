//
//	OS Windows
//	2019.11.17
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #9625	BABBA
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input9625.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int K;
	cin >> K;
	string str1, str2;
	register int k, sz, i, a = 0, b = 0;
	str1.clear(); str2.clear();
	str1.push_back('A');
	for (k = 0; k < K; ++k)
	{
		sz = str1.length();
		for (i = 0; i < sz; ++i)
		{
			if (str1[i] == 'A')
			{
				str2.push_back('B');
			}
			else
			{
				str2.push_back('B');
				str2.push_back('A');
			}
		}
		str1.clear();
		sz = str2.length();
		for (i = 0; i < sz; ++i) str1.push_back(str2[i]);
		str2.clear();
	}
	sz = str1.length();
	for (i = 0; i < sz; ++i)
	{
		if (str1[i] == 'A') a++;
		else b++;
	}
	cout << a << ' ' << b;
	return 0;
}