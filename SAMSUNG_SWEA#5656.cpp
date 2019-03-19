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
#include <string>
using namespace std;

typedef pair<int, int> PII;

const static int MAX_BALL = 4;
const static int MAX_ROW = 15;
const static int MAX_COL = 12;
const static int MAX_BRICKS = MAX_ROW * MAX_COL;
const static int DIRECT = 4;
const static int DIR[DIRECT][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Test
{
public:
	int Num_Ball;
	int Num_Brick_Col;
	int Num_Brick_Row;
	int Map[MAX_BALL][MAX_ROW][MAX_COL];
	int Input_Num_Brick;
	int Min_Remainder_Brick;
public:
	Test(const int N, const int C, const int R)
		: Num_Ball(N)
		, Num_Brick_Col(C)
		, Num_Brick_Row(R)
		, Input_Num_Brick(0)
		, Min_Remainder_Brick(MAX_BRICK)
	{
		(void)memset(&Map[0][0][0], 0, sizeof(Map));
	}
};

int main(int argv, char** argc)
{
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Result = MAX;	Row = 0; Col = 0;	Target_Col = 0;	Target_Row = 0;	Min_cnt = MAX;
		while (!Q.empty()) { Q.pop(); }
		while (!Stack.empty()) { Stack.pop(); }

		scanf("%d %d %d", &N, &Col, &Row);
		for (int r = 0; r < MAX_ROW; ++r)
		{
			for (int c = 0; c < MAX_COL; ++c)
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
				Map_copy[r][c] = Map[r][c];
			}
		}
		
		Shot(1);

		printf("#%d %d\n", test_case, Result);
	}
	return 0;
}

