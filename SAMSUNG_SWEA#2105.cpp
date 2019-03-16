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
static vector<int> Route;				//경로에서 같은 숫자가 있었는지 확인하기 위함
static stack<coor> Stack;
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
				for (int i = 1; i <= N - 2; ++i)
				{
					if (isSquare1(r + i, c + i) &&
						Map[r + i - 2][c + i - 1] != Map[r + i][c + i + 1] && Map[r + i - 2][c + i - 1] != Map[r + i + 1][c + i] &&
						Map[r + i - 1][c + i - 2] != Map[r + i][c + i + 1] && Map[r + i - 1][c + i - 2] != Map[r + i + 1][c + i])
					{
						cout << "RightDown (" << r + i << ", " << c + i << ")" << endl;
						RightDown += 2;
					}
					else
						break;
				}
				for (int i = 1; i < N - 2; ++i)
				{
					if (isSquare1(r + i, c - i) &&
						Map[r + i - 2][c - i + 1] != Map[r + i][c - i - 1] && Map[r + i - 2][c - i + 1] != Map[r + i + 1][c - i] &&
						Map[r + i - 1][c - i + 2] != Map[r + i][c - i - 1] && Map[r + i - 1][c - i + 2] != Map[r + i + 1][c - i])
					{
						cout << "LeftDown (" << r + i << ", " << c - i << ")" << endl;
						LeftDown += 2;
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

void Square2over()
{
	int temp = 0;
	for (int r = 1; r < N - 2; ++r)
	{
		for (int c = 1; c < N - 1; ++c)
		{
		
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
		Route.clear();
		while (!Stack.empty()) { Stack.pop(); }
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
