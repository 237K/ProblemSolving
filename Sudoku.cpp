//
//	OS Windows
//	2019.03.26
//
//	[Algorithm Problem Solving]
//
//	<스도쿠>
//
//	1. 9X9 형태의 스도쿠는 3X3형태의 그룹 9개로 구성됨
//	2. 각 그룹은 숫자 1 ~ 9 까지 하나씩만 들어가야 함
//	3. 가로줄에 숫자가 1 ~ 9 까지 하나씩만 들어가야 함
//	4. 세로줄에 숫자가 1 ~ 9 까지 하나씩만 들어가야 함
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;

const static int SIZE = 10;
const static int MAX_ERROR = 81;
static int map[SIZE][SIZE];
static pair<coor, int> error[MAX_ERROR];
static int e;
static int check_row[SIZE];
static int check_col[SIZE];
static int check_smallbox[SIZE];

void RowChange(int es, int ee)
{
	int changeNum;
	int changeRow;
	int changeCol;
	while (1)
	{
		if (es > ee)
			break;
		else
		{
			changeRow = error[ee].first.first;
			changeCol = error[ee].first.second;
			for (int c = 1; c < SIZE; ++c)
			{
				if (!check_row[c])
				{
					changeNum = c;
					check_row[c] = true;
					break;
				}
			}
			map[changeRow][changeCol] = changeNum;
			ee--;
		}
	}
}

void RowCheck(int row)
{
	int e_start = e;
	int e_end = 0;
	for (int c = 1; c < SIZE; ++c)
	{
		if (!check_row[map[row][c]])
			check_row[map[row][c]]++;
		else
		{
			error[e++] = pair<coor, int>(coor(row, c), map[row][c]);
		}
	}
	e_end = e;
	RowChange(e_start, e_end);
}

void ColChange(int es, int ee)
{
	int changeNum;
	int changeRow;
	int changeCol;
	while (1)
	{
		if (es > ee)
			break;
		else
		{
			changeRow = error[es].first.first;
			changeCol = error[es].first.second;
			for (int r = 1; r < SIZE; ++r)
			{
				if (!check_col[r])
				{
					changeNum = r;
					check_col[r] = true;
					break;
				}
			}
			map[changeRow][changeCol] = changeNum;
			ee--;
		}
	}
}

void ColCheck(int col)
{
	int e_start = e;
	int e_end = 0;
	for (int r = 1; r < SIZE; ++r)
	{
		if (!check_col[map[r][col]])
			check_col[map[r][col]]++;
		else
		{
			error[e++] = pair<coor, int>(coor(r, col), map[r][col]);
		}
	}
	e_end = e;
	ColChange(e_start, e_end);
}

void SmallChange(int es, int ee)
{
	int changeNum;
	int changeRow;
	int changeCol;
	while (1)
	{
		if (es > ee)
			break;
		else
		{
			changeRow = error[es].first.first;
			changeCol = error[es].first.second;
			for (int i = 0; i < SIZE; ++i)
			{
				if (!check_smallbox[i])
				{
					changeNum = i;
					check_smallbox[i] = true;
					break;
				}
			}
			map[changeRow][changeCol] = changeNum;
			ee--;
		}
	}
}

void SmallCheck(int row, int col)
{
	int e_start = e;
	int e_end = 0;
	for (int r = row; r < row + 3; ++r)
	{
		for (int c = col; c < col + 3; ++c)
		{
			if (!check_smallbox[map[r][c]])
				check_smallbox[map[r][c]]++;
			else
			{
				error[e++] = pair<coor, int>(coor(r, c), map[r][c]);
			}
		}
	}
	e_end = e;
	SmallChange(e_start, e_end);
}

void sudoku()
{
	for (int i = 1; i < SIZE; ++i)
	{
		(void)memset(check_row, 0, sizeof(check_row));
		(void)memset(check_col, 0, sizeof(check_col));

		RowCheck(i);
		ColCheck(i);
	}

	for (int r = 1; r < SIZE; r += 3)
	{
		for (int c = 1; c < SIZE; c += 3)
		{
			(void)memset(check_smallbox, 0, sizeof(check_smallbox));
			SmallCheck(r, c);
		}
	}
}

void PrintError()
{
	while (1)
	{
		if (e < 0)
			break;
		else
		{
			cout << "(" << error[e].first.first << ", " << error[e].first.second << ")" << "\n\n";
			e--;
		}
	}
}

void PrintMap()
{
	for (int r = 1; r < SIZE; ++r)
	{
		for (int c = 1; c < SIZE; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "\n\n";
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("testcase_sudoku.txt", "r", stdin);
	
	(void)memset(map, 0, sizeof(map));
	e = 0;

	for (int r = 1; r < SIZE; ++r)
	{
		for (int c = 1; c < SIZE; ++c)
		{
			cin >> map[r][c];
		}
	}
	
	cout << "error : " << e << '\n';
	PrintError();
	PrintMap();

	return 0;
}