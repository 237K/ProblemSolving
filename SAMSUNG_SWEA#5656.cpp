//
//	OS Windows
//	2019.03.05
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5656] <벽돌 깨기> (모의 SW 역량테스트)
//	
#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize("O3")
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const static int MAX_BALL = 5;
const static int MAX_ROW = 16;
const static int MAX_COL = 13;
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
	Test(const int _N, const int _W, const int _H)
		: Num_Ball(_N)
		, Num_Brick_Col(_W)
		, Num_Brick_Row(_H)
		, Input_Num_Brick(0)
		, Min_Remainder_Brick(MAX_BRICKS)
	{
		(void)memset(&Map[0][0][0], 0, sizeof(Map));
	}
	~Test() {}
	void PrintMap() const
	{
		for (int r = 0; r < Num_Brick_Row; ++r)
		{
			for (int c = 0; c < Num_Brick_Col; ++c)
			{
				cout<<Map[0][r][c]<<' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	int Simulation()
	{
		Min_Remainder_Brick = Input_Num_Brick;
		DFS_Shot(1, Input_Num_Brick);

		return Min_Remainder_Brick;
	}

	void DFS_Shot(const int ball, const int remainder)
	{
		if (remainder < 0)
		{
			Min_Remainder_Brick = 0;
			return;
		}
		if (remainder == 0)
		{
			Min_Remainder_Brick = 0;
			return;
		}
		if (ball > Num_Ball)
		{
			if (remainder < Min_Remainder_Brick)
			{
				Min_Remainder_Brick = remainder;
			}
			return;
		}

		for (int colidx = 0; colidx < Num_Brick_Col; ++colidx)
		{
			(void)memcpy(&Map[ball][0][0], &Map[ball - 1][0][0], sizeof(Map[ball]));
			const int initRowidx = FindBigBrick(Map[ball], colidx);

			int numRemoved = 0;
			DFS_Remove(initRowidx, colidx, numRemoved, Map[ball]);

			if (numRemoved > 0)
			{
				int tempBrick = Fall(Map[ball]);
				if(tempBrick == numRemoved)
					DFS_Shot((ball + 1), (remainder - tempBrick));
			}
		}
	}

	int FindBigBrick(const int(&Map)[MAX_ROW][MAX_COL], const int colidx)
	{
		int findRowidx = 0;
		for (int i = 0; i < Num_Brick_Row; ++i)
		{
			if (Map[i][colidx] > 0)
			{
				findRowidx = i;
				break;
			}
		}
		return findRowidx;
	}
	void DFS_Remove(const int rowidx, const int colidx, int &numRemoved, int (&Map)[MAX_ROW][MAX_COL])
	{
		int brick = 0;
		brick = RemoveBrick(rowidx, colidx, numRemoved, Map);
		if (brick < 0)
			return;

		if (brick > 1)
		{
			for (int dir = 0; dir < DIRECT; ++dir)
			{
				for (int i = 1; i < brick; ++i)
				{
					int row = rowidx + i * DIR[dir][0];
					int col = colidx + i * DIR[dir][1];
					if (row < Num_Brick_Row && col < Num_Brick_Col)
						DFS_Remove(row, col, numRemoved, Map);
				}
			}
		}
	}

	int RemoveBrick(const int rowidx, const int colidx, int &numRemoved, int(&Map)[MAX_ROW][MAX_COL])
	{
		if (rowidx >= Num_Brick_Row || colidx >= Num_Brick_Col)
			return -1;

		int brick = Map[rowidx][colidx];
		if (brick <= 0)
			return 0;
		numRemoved++;
		Map[rowidx][colidx] = -1;
		return brick;
	}

	int Fall(int(&Map)[MAX_ROW][MAX_COL])
	{
		int brick = 0;
		for (int colidx = 0; colidx < Num_Brick_Col; ++colidx)
		{
			int rowBottom = 0;
			for (int rowidx = Num_Brick_Row - 1; rowidx >= 0; --rowidx)
			{
				int UpperBrick = Map[rowidx][colidx];
				if (UpperBrick < 0)
				{
					if (rowBottom == 0)
					{
						rowBottom = rowidx;
					}
					Map[rowidx][colidx] = 0;
					brick++;
				}
				else
				{
					if (rowBottom > 0)
					{
						Map[rowidx][colidx] = Map[rowBottom][colidx];
						Map[rowBottom--][colidx] = UpperBrick;
					}
				}
			}
		}
		return brick;
	}
};


int main(int argv, char** argc)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	int N, W, H;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0, W = 0, H = 0;
		cin >> N >> W >> H;
		Test test(N, W, H);

		for (int r = 0; r < H; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin>>test.Map[0][r][c];
				if (test.Map[0][r][c] > 0)
					test.Input_Num_Brick++;
			}
		}
		cout << "#" << test_case << ' ' << test.Simulation() << '\n';
	}
	return 0;
}

