//
//	OS Windows
//	2019.08.17
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1215] (D4) È¸¹®1
//

#include <iostream>
#include <stack>
using namespace std;
const static int SZ = 8;
const static int T = 10;
static char map[SZ][9];
static int N;
inline int simul()
{
	register int ret = 0, r, c, i, half;
	stack<char> ST;
	half = N / 2;
	for (r = 0; r < SZ; ++r)
	{
		for (c = 0; c <= (SZ - N); ++c)
		{
			while (!ST.empty()) { ST.pop(); }
			for (i = c; i < c + half; ++i)
			{
				ST.push(map[r][i]);
			}
			for (i = c + N - half; i < c + N; ++i)
			{
				if (map[r][i] != ST.top()) break;
				else ST.pop();
			}
			if (ST.empty()) ret++;
		}
	}
	for (c = 0; c < SZ; ++c)
	{
		for (r = 0; r <= (SZ - N); ++r)
		{
			while (!ST.empty()) { ST.pop(); }
			for (i = r; i < r + half; ++i)
			{
				ST.push(map[i][c]);
			}
			for (i = r + N - half; i < r + N; ++i)
			{
				if (map[i][c] != ST.top()) break;
				else ST.pop();
			}
			if (ST.empty()) ret++;
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("s_input1215.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, r;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		for (r = 0; r < SZ; ++r)
			cin >> map[r];
		cout << "#" << tc << ' ' << simul() << '\n';
	}
	return 0;
}