//
//	OS Windows
//	2019.03.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2112] <보호 필름> (모의 SW 역량테스트)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const static int MAX_THICK = 13;
const static int MAX_CELL = 20;

static int film[MAX_THICK][MAX_CELL];
static bool check[MAX_THICK];
static int D, W, K;
static int Result;

bool Test(int cast)
{
	int A, B;
	bool Flag;
	if (cast)
	{
		for (int c = 0; c < W; ++c)
		{
			A = 0;
			B = 0;
			Flag = false;
			for (int r = 0; r < D; ++r)
			{
				if (!film[r][c] || check[r])
				{
					A++;
					B = 0;
				}
				else if (film[r][c])
				{
					B++;
					A = 0;
				}
				if (A == K || B == K)
				{
					Flag = true;
					break;
				}
			}
			if (!Flag)
				return false;
		}
	}
	else
	{
		for (int c = 0; c < W; ++c)
		{
			A = 0;
			B = 0;
			Flag = false;
			for (int r = 0; r < D; ++r)
			{
				if (!film[r][c] || check[r])
				{
					A++;
					B = 0;
				}
				else if (film[r][c] || check[r])
				{
					B++;
					A = 0;
				}
				if (A == K || B == K)
				{
					Flag = true;
					break;
				}
			}
			if (!Flag)
				return false;
		}
	}
	return true;
}

void Casting(int row, int cast)
{
	if (row > D || cast > Result)
		return;
	else
	{
		check[row] = true;
		if (Test(0) || Test(1))
			Result = min(Result, cast);
		else
		{
			for (int r = row + 1; r < D; ++r)
			{
				Casting(r, cast + 1);
			}
			check[row] = false;
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input2112.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(film, 0, sizeof(film));
		(void)memset(check, false, sizeof(check));
		cin >> D >> W >> K;
		Result = D;
		for (int r = 0; r < D; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin >> film[r][c];
			}
		}
		Casting(0, 0);
		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}