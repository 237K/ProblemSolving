//
//	OS Windows
//	2020.06.04
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <BOJ#17779> 게리맨더링 2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int SZ = 21;
const static int DIR = 4;
static int map[SZ][SZ], seongeogu[SZ][SZ], N;
inline void print()
{
	register int r, c;
	cout << "============================================\n";
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cout << seongeogu[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "============================================\n";
}
inline void set_seongeogu(int X, int Y, int D1, int D2)
{
	(void)memset(seongeogu, 0, sizeof(seongeogu));
	register int x, y, x1, y1, d1, d2, start, end;
	//	5번 선거구
	for (d1 = 0; d1 <= D1; ++d1)
	{
		x = X + d1;
		y = Y - d1;
		seongeogu[x][y] = 5;
	}
	for (d2 = 0; d2 <= D2; ++d2)
	{
		x = X + d2;
		y = Y + d2;
		seongeogu[x][y] = 5;
	}
	x1 = X + D1;
	y1 = Y - D1;
	for (d2 = 0; d2 <= D2; ++d2)
	{
		x = x1 + d2;
		y = y1 + d2;
		seongeogu[x][y] = 5;
	}
	x1 = X + D2;
	y1 = Y + D2;
	for (d1 = 0; d1 <= D1; ++d1)
	{
		x = x1 + d1;
		y = y1 - d1;
		seongeogu[x][y] = 5;
	}
	for (x = X; x < X + D1 + D2; ++x)
	{
		start = end = -1;
		for (y = 0; y < N; ++y)
		{
			if (seongeogu[x][y] == 5)
			{
				if (start == -1)
				{
					start = y;
					continue;
				}
				else
				{
					end = y;
					break;
				}
			}
		}
		if (start == -1 || end == -1)
			continue;
		for (y = start + 1; y < end; ++y)
			seongeogu[x][y] = 5;
	}
	//	1번 선거구
	for (x = 0; x < X + D1; ++x)
	{
		for (y = 0; y <= Y; ++y)
		{
			if (seongeogu[x][y] == 5)
				continue;
			seongeogu[x][y] = 1;
		}
	}
	//	2번 선거구
	for (x = 0; x <= X + D2; ++x)
	{
		for (y = Y+1; y < N; ++y)
		{
			if (seongeogu[x][y])
				continue;
			seongeogu[x][y] = 2;
		}
	}
	//	3번 선거구
	for (x = X+D1; x < N; ++x)
	{
		for (y = 0; y < Y-D1+D2; ++y)
		{
			if (seongeogu[x][y])
				continue;
			seongeogu[x][y] = 3;
		}
	}
	//	4번 선거구
	for (x = X+D2+1; x < N; ++x)
	{
		for (y = Y-D1+D2; y < N; ++y)
		{
			if (seongeogu[x][y])
				continue;
			seongeogu[x][y] = 4;
		}
	}
	//print();
}
inline int cal()
{
	register int i, r, c, sum, top = 0, low = 2147000000;
	for (i = 1; i <= 5; ++i)
	{
		sum = 0;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				if (i != seongeogu[r][c])
					continue;
				sum += map[r][c];
			}
		}
		if (top < sum) top = sum;
		if (low > sum) low = sum;
	}
	return top - low;
}
inline int simul()
{
	register int x, y, d1, d2, cur, ret = 2147000000;
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			for (d1 = 1; d1 < N; ++d1)
			{
				if (y - d1 < 0)
					break;
				for (d2 = 1; d2 < N; ++d2)
				{
					if (x + d1 + d2 >= N || y + d2 >= N)
						break;
					set_seongeogu(x, y, d1, d2);
					//print();
					cur = cal();
					//cout << "=====================================\n";
					//cout << "(" << x << ", " << y << "), D1 : " << d1 << ", D2 : " << d2 << "\n";
					//cout << "cal : " << cur << "\n\n";
					if (ret > cur)
						ret = cur;
				}
			}
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("binput17779.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
		}
	}
	//set_seongeogu(2, 2, 1, 1);
	//print();
	//cout << cal();
	cout << simul();
	return 0;
}