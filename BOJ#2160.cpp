//
//	OS Windows
//	2019.05.22
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2160	그림 비교
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 51;
const static int R = 5;
const static int C = 7;
static char map[MAX][R][C];
static int N;
inline pair<int, int> simul()
{
	int ret = 35, tmp, idx1, idx2;
	register int i, j, r, c;
	bool flag;
	for (i = 1; i < N; ++i)
	{
		for (j = i + 1; j <= N; ++j)
		{
			tmp = 0;
			flag = false;
			for (r = 0; r < R; ++r)
			{
				for (c = 0; c < C; ++c)
				{
					if (map[i][r][c] != map[j][r][c]) tmp++;
					if (tmp > ret)
					{
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (ret > tmp)
			{
				ret = tmp;
				idx1 = i;
				idx2 = j;
			}
		}
	}
	return { idx1, idx2 };
}
int main(void)
{
	freopen("input2160.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int n, r;
	cin >> N;
	for (n = 1; n <= N; ++n)
	{
		for (r = 0; r < R; ++r)
		{
			cin >> map[n][r];
		}
	}
	pair<int, int> ret = simul();
	cout << ret.first<<' '<<ret.second;
	return 0;
}