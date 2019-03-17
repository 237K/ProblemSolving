//
//	OS Windows
//	2019.03.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2105] <디저트 카페>
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> coor;
const static int MAP_SIZE = 20;
static int N;
static int Map[MAP_SIZE][MAP_SIZE];
static bool Check[MAP_SIZE][MAP_SIZE];
static int Result;

bool isSquare1(int r, int c)
{
	if (r-1 >= 0 &&
		c+1 < N &&
		r+1 < N &&
		c-1 >= 0 &&
		Map[r - 1][c] != Map[r][c + 1] &&
		Map[r - 1][c] != Map[r + 1][c] &&
		Map[r - 1][c] != Map[r][c - 1] &&
		Map[r][c + 1] != Map[r + 1][c] &&
		Map[r][c + 1] != Map[r][c - 1] &&
		Map[r + 1][c] != Map[r][c - 1])
		return true;
	else
		return false;
}

void Square1()
{
	for (int r = 1; r < N - 1; ++r)
	{
		for (int c = 1; c < N - 1; ++c)
		{
			cout << "For (" << r << ", " << c << ")" << endl;
			int temp = -2147000000;
			int RightDown = 0;
			int LeftDown = 0;
			if (isSquare1(r, c))
			{
				temp = 4;
				cout << "(" << r << ", " << c << ")" << endl;

				int rdidx = 1;
				bool isrd = true;
				while (1)
				{
					if (isSquare1(r + rdidx, c + rdidx))
					{
						for (int j = rdidx; j > 0; --j)
						{
							if (Map[r + rdidx - j - 1][c + rdidx - j] != Map[r + rdidx][c + rdidx + 1] &&
								Map[r + rdidx - j - 1][c + rdidx - j] != Map[r + rdidx + 1][c + rdidx] &&
								Map[r + rdidx - j][c + rdidx - j - 1] != Map[r + rdidx][c + rdidx + 1] &&
								Map[r + rdidx - j][c + rdidx - j - 1] != Map[r + rdidx + 1][c + rdidx])
							{

							}
							else
							{
								isrd = false;
								break;
							}
						}
						if (isrd)
						{
							cout << "RightDown (" << r + rdidx << ", " << c + rdidx << ")" << endl;
							RightDown += 2;
						}
						else
							break;

						rdidx++;
					}
					else
						break;
				}

				int ldidx = 1;
				bool isld = true;
				while(1)
				{
					if (isSquare1(r + ldidx, c - ldidx))
					{
						for (int j = ldidx; j > 0; --j)
						{
							if (Map[r + ldidx - j - 1][c - ldidx + j] != Map[r+ ldidx +1][c- ldidx] &&
								Map[r + ldidx - j - 1][c - ldidx + j] != Map[r+ ldidx][c- ldidx -1] &&
								Map[r + ldidx - j][c- ldidx + j + 1] != Map[r+ ldidx +1][c- ldidx] &&
								Map[r + ldidx - j][c- ldidx + j + 1] != Map[r+ ldidx][c- ldidx -1])
							{
								
							}
							else
							{
								isld = false;
								break;
							}
						}
						if (isld)
						{
							cout << "LeftDown (" << r + ldidx << ", " << c - ldidx << ")" << endl;
							LeftDown += 2;
						}
						else
							break;

						ldidx++;
					}
					else
						break;
				}

				temp += max(RightDown, LeftDown);
				cout << temp << endl;
			}

			if (temp > Result)
				Result = temp;
		}
	}
}

int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("s_input2105.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0;
		Result = -2147000000;
		for (int row = 0; row < N; ++row)
		{
			for (int col = 0; col < N; ++col)
			{
				Map[row][col] = 0;
				Check[row][col] = false;
			}
		}

		scanf("%d", &N);
		for (int row = 0; row < N; ++row)
		{
			for (int col = 0; col < N; ++col)
			{
				scanf("%d", &Map[row][col]);
			}
		}

		Square1();

		if (Result == -2147000000)
			printf("#%d -1\n", test_case);
		else
			printf("#%d %d\n", test_case, Result);

		cout << endl << endl;
	}
	return 0;
}
