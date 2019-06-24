//
//	OS Windows
//	2019.06.24
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4751] (D3) 다솔이의 다이아몬드 장식
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const static int LEN = 202;
const static int DIR = 8;
static int dir[DIR][2] = { {-2, 0}, {-1, -1}, {-1, 1}, {0, -2}, {0, 2}, {1, -1}, {1, 1}, {2, 0} };
static string input;
static char output[5][LEN];

inline void init(int sz)
{
	register int i, j;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < sz; ++j)
		{
			output[i][j] = '.';
		}
	}
}
inline void print(int sz)
{
	register int i, j;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < sz; ++j)
		{
			cout << output[i][j];
		}
		cout << '\n';
	}
}
int main(void)
{
	freopen("s_input4751.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int tc, i, j, len, sz, cr, cc, tmp;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> input;
		len = input.length();
		sz = len * 4 + 1;
		init(sz);
		for (i = 0; i < len; ++i)
		{
			tmp = 2 + 4 * i;
			for (j = 0; j < DIR; ++j)
			{
				cr = 2 + dir[j][0];
				cc = tmp + dir[j][1];
				output[cr][cc] = '#';
			}
			output[2][tmp] = input[i];
		}
		print(sz);
	}
	return 0;
}