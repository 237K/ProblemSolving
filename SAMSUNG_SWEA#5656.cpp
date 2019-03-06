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
static int N, Row, Col;
static int Result;

void Bomb(int shot_row, int shot_col, int range);
void Drop(int drop_row, int drop_col);
void Shot(int n);
int Count();
void Print();
void MapCopy();
void MapInit();

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
		scanf("%d %d %d", &N, &Col, &Row);
		for (int r = 0; r < MAX_ROW; ++r)
		{
			for (int c = 0; c < MAX_COLUMN; ++c)
			{
				Map[r][c] = 0;
				Map_copy[r][c] = 0;
				Check[r][c] = false;
			}
		}

		for (int r = 0; r < Row; ++r)
		{
			for (int c = 0; c < Col; ++c)
			{
				scanf("%d", &Map[r][c]);
				//Map_copy[r][c] = Map[r][c];
			}
		}

		Print();

		Bomb(1, 2, 1);
		Bomb(2, 2, 3);
		Bomb(8, 6, 2);
		Print();

		printf("#%d %d\n", test_case, Result);
	}
}

void Drop(int drop_row, int drop_col)
{
	for (int dr = drop_row; dr > 0; --dr)
	{
		if (Map[dr][drop_col] == 0 && Map[dr-1][drop_col] != 0)
		{
			Map[dr][drop_col] = Map[dr - 1][drop_col];
			Map[dr - 1][drop_col] = 0;
		}
	}
}

void Bomb(int shot_row, int shot_col, int range)
{
	//int range = Map[shot_row][shot_col] - 1;
	cout << "(" << shot_row << ", " << shot_col << ")" << endl;
	//Print();
	cout << endl;


	Map[shot_row][shot_col] = 0;
	for (int b = 1; b <= range; ++b)
	{
		if (shot_row + b < Row)
		{
			if (Map[shot_row + b][shot_col] == 1)
			{
				Map[shot_row + b][shot_col] = 0;
				Drop(shot_row + b, shot_col);
			}
			else if (Map[shot_row + b][shot_col] > 1)
			{
				int _range = Map[shot_row + b][shot_col];
				Bomb(shot_row + b, shot_col, _range);
				Drop(shot_row + b, shot_col);
			}
		}
		if (shot_row - b >= 0)
		{
			if (Map[shot_row - b][shot_col] == 1)
			{
				Map[shot_row - b][shot_col] = 0;
				Drop(shot_row - b, shot_col);
			}
			else if (Map[shot_row - b][shot_col] > 1)
			{
				int _range = Map[shot_row - b][shot_col];
				Bomb(shot_row - b, shot_col, _range);
				Drop(shot_row - b, shot_col);
			}
		}
		if (shot_col + b < Col)
		{
			if (Map[shot_row][shot_col + b] == 1)
			{
				Map[shot_row][shot_col + b] = 0;
				Drop(shot_row, shot_col + b);
			}
			else if (Map[shot_row][shot_col + b] > 1)
			{
				int _range = Map[shot_row][shot_col + b];
				Bomb(shot_row, shot_col + b, _range);
				Drop(shot_row, shot_col + b);
			}
		}
		if (shot_col - b >= 0)
		{
			if (Map[shot_row][shot_col - b] == 1)
			{
				Map[shot_row][shot_col - b] = 0;
				Drop(shot_row, shot_col - b);
			}
			else if (Map[shot_row][shot_col - b] > 1)
			{
				int _range = Map[shot_row][shot_col - b];
				Bomb(shot_row, shot_col - b, _range);
				Drop(shot_row, shot_col + b);
			}
		}
	}
}

void Shot(int n)
{

}

int Count()
{
	int C = 0;
	for (int r = 0; r < Row; ++r)
	{
		for (int c = 0; c < Col; ++c)
		{
			if (Map[r][c] > 0)
				C++;
		}
	}
	return C;
}

void Print()
{
	for (int r = 0; r < Row; ++r)
	{
		for (int c = 0; c < Col; ++c)
		{
			cout << Map[r][c] << ' ';
		}
		cout << endl << endl;
	}
	cout << "Result : " << Result << endl << endl;
}

void MapCopy()
{
	for (int r = 0; r < Row; ++r)
	{
		for (int c = 0; c < Col; ++c)
		{
			Map_copy[r][c] = Map[r][c];
		}
	}
}

void MapInit()
{
	for (int r = 0; r < Row; ++r)
	{
		for (int c = 0; c < Col; ++c)
		{
			Map[r][c] = Map_copy[r][c];
		}
	}
}