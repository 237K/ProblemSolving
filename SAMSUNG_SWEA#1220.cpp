//
//	OS Windows
//	2019.07.20
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1220] (D3) Magnetic
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;
const static int SZ = 100;
static int T = 10;
static int N;
static int map[SZ][SZ];
inline int deadlock()
{
	stack<int> S;
	register int r, c, ret = 0;
	for (c = 0; c < N; ++c)
	{
		while (!S.empty()) { S.pop(); }
		for (r = 0; r < N; ++r)
		{
			if (map[r][c] == 1)
			{
				if (S.empty()) S.push(1);
				else if (S.top() == 1) continue;
			}
			else if (map[r][c] == 2)
			{
				if (S.empty()) continue;
				else if (S.top() == 2) continue;
				else if (S.top() == 1)
				{
					ret++;
					S.pop();
				}
			}
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, r, c;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		for (r = 0; r < N; ++r)
			for (c = 0; c < N; ++c)
				cin >> map[r][c];
		cout << "#" << tc << ' ' << deadlock() << '\n';
	}
	return 0;
}