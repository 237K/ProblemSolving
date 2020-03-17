//
//	OS Windows
//	2020.03.16
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1314> 문자사각형2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const static int SZ = 100;
const static string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char table[SZ][SZ];
static int N;
inline void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cout << table[r][c] << ' ';
		}
		cout << "\n";
	}
}
int main(int argc, char** argv)
{
	freopen("jinput1314.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r = 0, c = 0, i = 0;
	for (c = 0; c < N; ++c)
	{
		if (c % 2)
		{
			for (r = N-1; r >= 0; --r)
			{
				table[r][c] = str[i++];
				i %= 26;
			}
		}
		else
		{
			for (r = 0; r < N; ++r)
			{
				table[r][c] = str[i++];
				i %= 26;
			}
		}
	}
	print();
	return 0;
}