//
//	OS Windows
//	2019.03.27
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1974] <½ºµµÄí °ËÁõ> (D2)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int SIZE = 10;
static int map[SIZE][SIZE];
static int check_row[SIZE];
static int check_col[SIZE];
static int check_smallbox[SIZE];

bool RowCheck(int row)
{
	for (int c = 1; c < SIZE; ++c)
	{
		if (!check_row[map[row][c]])
			check_row[map[row][c]]++;
		else
			return false;
	}
	return true;
}

bool ColCheck(int col)
{
	for (int r = 1; r < SIZE; ++r)
	{
		if (!check_col[map[r][col]])
			check_col[map[r][col]]++;
		else
			return false;
	}
	return true;
}

bool SmallCheck(int row, int col)
{
	for (int r = row; r < row + 3; ++r)
	{
		for (int c = col; c < col + 3; ++c)
		{
			if (!check_smallbox[map[r][c]])
				check_smallbox[map[r][c]]++;
			else
				return false;
		}
	}
	return true;
}

int sudoku()
{
	for (int i = 1; i < SIZE; ++i)
	{
		(void)memset(check_row, 0, sizeof(check_row));
		(void)memset(check_col, 0, sizeof(check_col));

		if (!RowCheck(i) || !ColCheck(i))
			return 0;
	}

	for (int r = 1; r < SIZE; r += 3)
	{
		for (int c = 1; c < SIZE; c += 3)
		{
			(void)memset(check_smallbox, 0, sizeof(check_smallbox));
			if (!SmallCheck(r, c))
				return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input1974.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(&map[0][0], 0, sizeof(map));
		
		for (int r = 1; r < SIZE; ++r)
		{
			for (int c = 1; c < SIZE; ++c)
			{
				cin >> map[r][c];
			}
		}
		cout<<"#"<<test_case<<' '<<sudoku()<<'\n';
	}
	return 0;
}