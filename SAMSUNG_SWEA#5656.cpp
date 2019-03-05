//
//	OS Windows
//	2019.03.05
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5656] <벽돌 깨기> (모의 SW 역량테스트)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const static int MAX_ROW = 15;
const static int MAX_COLUMN = 12;
const static int MAX = 2147000000;

static bool Check[MAX_ROW][MAX_COLUMN];
static int Map[MAX_ROW][MAX_COLUMN];
static int Map_copy[MAX_ROW][MAX_COLUMN];
//static queue<PII> Q;
static int N, H, W;
static int Result;

void Bomb(int shot_row, int shot_col, int row, int col);
void Shot(int n, int row, int col);
int Count(int row, int col);
void Print(int row, int col);
void MapCopy(int row, int col);
void MapInit(int row, int col);

int main(int argv, char** argc)
{
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	int W, H;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Result = MAX;	W = 0; H = 0;
		//while (!Q.empty()) { Q.pop(); }
		scanf("%d %d %d", &N, &W, &H);
		for (int r = 0; r < MAX_ROW; ++r)
		{
			for (int c = 0; c < MAX_COLUMN; ++c)
			{
				Map[r][c] = -1;
				Map_copy[r][c] = -1;
				Check[r][c] = false;
			}
		}

		for (int r = 0; r < H; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				scanf("%d", &Map[r][c]);
				Map_copy[r][c] = Map[r][c];
			}
		}
		Shot(0, H, W);
		printf("#%d %d\n", test_case, Result);
	}
}

void Bomb(int shot_row, int shot_col, int row, int col)
{
	int Bomb_range = Map[shot_row][shot_col] - 1;
	//if (Bomb_range == 0)
		//Map[shot_row][shot_col] = 0;
	//else
	//{

	MapCopy(row, col);

		for (int i = 0; i <= Bomb_range; ++i)
		{
			if (shot_row + i < row)
			{
				if (Map[shot_row + i][shot_col] == 1)
					Map[shot_row + i][shot_col] = 0;
				else if (Map[shot_row + i][shot_col] > 1)
				{
					Bomb_range += (Map[shot_row + i][shot_col] - 1);
					Map[shot_row + i][shot_col] = 0;
				}
			}

			if (shot_col + i < col)
			{
				if (Map[shot_row][shot_col + i] == 1)
					Map[shot_row][shot_col + i] = 0;
				else if (Map[shot_row][shot_col + i] > 1)
				{
					Bomb_range += (Map[shot_row][shot_col + i] - 1);
					Map[shot_row][shot_col + i] = 0;
				}
			}
			if (shot_col - i >= 0)
			{
				if (Map[shot_row][shot_col - i] == 1)
					Map[shot_row][shot_col - i] = 0;
				else if (Map[shot_row][shot_col - i] > 1)
				{
					Bomb_range += (Map[shot_row][shot_col - i] - 1);
					Map[shot_row][shot_col + i] = 0;
				}
			}
		}
		/*
		while (Bomb_range > 0)
		{
			if (shot_row + Bomb_range < row)
			{
				//int temp1 = Map[shot_row + Bomb_range][shot_col];
				
				Bomb(shot_row + Bomb_range, shot_col, row, col);
				Map[shot_row + Bomb_range][shot_col] = 0;
				//Map[shot_row + Bomb_range][shot_col] = temp1;
			}
			if (shot_col + Bomb_range < col)
			{
				//int temp2 = Map[shot_row][shot_col + Bomb_range];
				
				Bomb(shot_row, shot_col + Bomb_range, row, col);
				Map[shot_row][shot_col + Bomb_range] = 0;
				//Map[shot_row][shot_col + Bomb_range] = temp2;
			}
			if (shot_col - Bomb_range >= 0)
			{
				//int temp3 = Map[shot_row][shot_col - Bomb_range];
				
				Bomb(shot_row, shot_col - Bomb_range, row, col);
				Map[shot_row][shot_col - Bomb_range] = 0;
				//Map[shot_row][shot_col - Bomb_range] = temp3;
			}
			Bomb_range--;
		}
		*/
	//}
}

void Shot(int n, int row, int col)
{
	if (N == n)
	{
		int cur_cnt = Count(row, col);
		if (Result > cur_cnt)
			Result = cur_cnt;

		//Print(row, col);

		MapInit(row, col);

		return;
	}
	else
	{
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				if (Map[r][c] > 0 && Map[r-1][c] == 0 && Check[r][c] == false)
				{
					int temp = Map[r][c];
					Bomb(r, c, row, col);
					//cout << "(" << r << ", " << c << ") , n : " <<n<< endl;
					Check[r][c] = true;
					Shot(n + 1, row, col);
					Check[r][c] = false;
					Map[r][c] = temp;
				}
			}
		}
	}
}

int Count(int row, int col)
{
	int C = 0;
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			if (Map[r][c] > 0)
				C++;
		}
	}
	return C;
}

void Print(int row, int col)
{
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			cout << Map[r][c] << ' ';
		}
		cout << endl << endl;
	}
	cout << "Result : " << Result << endl << endl;
}

void MapCopy(int row, int col)
{
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			Map_copy[r][c] = Map[r][c];
		}
	}
}

void MapInit(int row, int col)
{
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			Map[r][c] = Map_copy[r][c];
		}
	}
}