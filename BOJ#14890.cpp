//
//	OS Windows
//	2019.05.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14890	°æ»ç·Î
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const static int SZ = 101;

static int map[SZ][SZ];
static int N, L;
inline int simul()
{
	register int r, c, nr, nc, ret = 0, num_same_h = 1;
	bool flag = true;
	for (r = 0; r < N; ++r)
	{
		num_same_h = 1; flag = true;
		for (c = 0; c < N - 1; ++c)
		{
			if (map[r][c] == map[r][c + 1]) num_same_h++;
			else if (map[r][c] - map[r][c + 1] > 1 || map[r][c] - map[r][c + 1] < -1) break;
			else if (map[r][c] < map[r][c + 1])
			{
				if (num_same_h >= L) num_same_h = 1;
				else break;
			}
			else if (map[r][c] > map[r][c + 1])
			{
				num_same_h = 1;
				for (nc = c + 1; nc < N; ++nc)
				{
					if (map[r][nc] == map[r][nc + 1])
					{
						if ((++num_same_h) >= L)
						{
							num_same_h = 0;
							c += L-1;
							break;
						}
					}
					else if (num_same_h >= L)
					{
						num_same_h = 0;
						c += L-1;
						break;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (c >= N - 2)	ret++;
		}
	}

	for (c = 0; c < N; ++c)
	{
		num_same_h = 1; flag = true;
		for (r = 0; r < N - 1; ++r)
		{
			if (map[r][c] == map[r+1][c]) num_same_h++;
			else if (map[r][c] - map[r + 1][c] > 1 || map[r][c] - map[r+1][c] < -1) break;
			else if (map[r][c] < map[r + 1][c])
			{
				if (num_same_h >= L) num_same_h = 1;
				else break;
			}
			else if (map[r][c] > map[r + 1][c])
			{
				num_same_h = 1;
				for (nr = r + 1; nr < N; ++nr)
				{
					if (map[nr][c] == map[nr + 1][c])
					{
						if ((++num_same_h) >= L)
						{
							num_same_h = 0;
							r += L-1;
							break;
						}
					}
					else if (num_same_h >= L)
					{
						num_same_h = 0;
						r += L-1;
						break;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (r >= N - 2) ret++;
		}
	}

	return ret;
}
int main(void)
{
	freopen("input14890.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	cin >> N >> L;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << simul();
	return 0;
}