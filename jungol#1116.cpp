//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1116> ÃÖ´ñ°ª
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int SZ = 9;
static int cur, top, row, col;
int main(int argc, char** argv)
{
	freopen("jinput1116.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	top = 0;
	register int r, c;
	for (r = 1; r <= SZ; ++r)
	{
		for (c = 1; c <= SZ; ++c)
		{
			cin >> cur;
			if (top < cur)
			{
				top = cur;
				row = r;
				col = c;
			}
		}
	}
	cout << top << '\n' << row << ' ' << col;
	return 0;
}