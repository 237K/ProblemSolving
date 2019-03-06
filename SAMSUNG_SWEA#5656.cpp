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
#include <stack>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const static int MAX_ROW = 15;
const static int MAX_COLUMN = 12;
const static int MAX = 2147000000;

static bool Check[MAX_ROW][MAX_COLUMN];
static int Map[MAX_ROW][MAX_COLUMN];
static int Map_copy[MAX_ROW][MAX_COLUMN];
static int Break[MAX_COLUMN];
static int Target_Col;
static int Target_Row;
static queue<PII> Q;
static stack<PII> Stack;
static int N, Row, Col;
static int Result;


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

void Drop()
{
	for (int c = 0; c < Col; ++c)
	{
		int cnt = Row - 1;
		for (int r = Row - 1; r >= 0; --r)
		{
			if (Map[r][c] != 0)
			{
				if (Map[cnt][c] == 0)
				{
					Map[cnt][c] = Map[r][c];
					Map[r][c] = 0;
				}
				else
				{
					Map[cnt][c] = Map[r][c];
				}
				cnt--;
			}
		}
	}

}

void Bomb(int shot_row, int shot_col)
{
	
	cout << "(" << shot_row << ", " << shot_col << "), n : " << N << endl << endl;

	Q.push(PII(shot_row, shot_col));

	while (!Q.empty())
	{
		PII cur = Q.front();
		int range = Map[cur.first][cur.second]-1;
		Q.pop();
		if (range < 0)
			continue;

		Map[cur.first][cur.second] = 0;

		if (range == 0)
			continue;
			for (int i = 1; i <= range; ++i)
			{
				if (cur.first + i < Row)
				{
					if (Map[cur.first + i][cur.second] == 1)
					{
						Map[cur.first + i][cur.second] = 0;
					}
					else if (Map[cur.first + i][cur.second] > 1)
					{
						Q.push(PII(cur.first + i, cur.second));
					}
				}

				if (cur.first - i >= 0)
				{
					if (Map[cur.first - i][cur.second] == 1)
					{
						Map[cur.first - i][cur.second] = 0;
					}
					else if (Map[cur.first - i][cur.second] > 1)
					{
						Q.push(PII(cur.first - i, cur.second));
					}
				}

				if (cur.second + i < Col)
				{
					if (Map[cur.first][cur.second + i] == 1)
					{
						Map[cur.first][cur.second + i] = 0;
					}
					else if (Map[cur.first][cur.second + i] > 1)
					{
						Q.push(PII(cur.first, cur.second + i));
					}
				}

				if (cur.second - i >= 0)
				{
					if (Map[cur.first][cur.second - i] == 1)
					{
						Map[cur.first][cur.second - i] = 0;
					}
					else if (Map[cur.first][cur.second - i] > 1)
					{
						Q.push(PII(cur.first, cur.second - i));
					}
				}
			}
	}
	Drop();
}

bool FindTarget(int n)
{
	bool isTarget = false;
	int cnt = 0;
	for (int c = 0; c < Col; ++c)
	{
		for (int r = Row-1; r >= 0; --r)
		{
			if (Map[r][c] == 1)
			{
				cnt++;
			}
			else if (Map[r][c] > 1)
			{
				if (cnt <= n)
				{
					Break[c] = cnt;
					Target_Col = c;
					Target_Row = r;
					isTarget = true;
					return isTarget;
				}
			}
		}
	}
	return isTarget;
}


void Shot()
{
	int temp_cnt = 0;
	if (N == 0)
	{
		Print();


		return;
	}
	else
	{
		for (int r = 0; r < Row; ++r)
		{
			for (int c = 0; c < Col; ++c)
			{
				if (Map[r][c] > 0 && Check[r][c] == false)
				{

					Check[r][c] = true;
					MapCopy();

					

					Bomb(r, c);

						MapCopy();
						N--;


					Shot();
					Check[r][c] = false;
					MapInit();
					N++;
				}
			}
		}
	}
}



int main(int argv, char** argc)
{
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Result = MAX;	Row = 0; Col = 0;	Target_Col = 0;	Target_Row = 0;
		while (!Q.empty()) { Q.pop(); }
		while (!Stack.empty()) { Stack.pop(); }

		scanf("%d %d %d", &N, &Col, &Row);
		for (int r = 0; r < MAX_ROW; ++r)
		{
			for (int c = 0; c < MAX_COLUMN; ++c)
			{
				Map[r][c] = 0;
				Break[c] = -1;
				Map_copy[r][c] = 0;
				Check[r][c] = false;
			}
		}

		for (int r = 0; r < Row; ++r)
		{
			for (int c = 0; c < Col; ++c)
			{
				scanf("%d", &Map[r][c]);
				Map_copy[r][c] = Map[r][c];
			}
		}
		
		Shot();

		printf("#%d %d\n", test_case, Result);
	}
}

