//
//	OS Windows
//	2019.03.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5656] <벽돌 깨기> (모의 SW 역량테스트)
//	ver1. 시간초과	
//	ver2. 파괴력이 큰 블록을 찾아서 깨는 코드 추가
//
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;

const static int MAX_BALL = 5;
const static int MAX_ROW = 16;
const static int MAX_COL = 13;
const static int DIRECT = 4;
const static int DIR[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

static int Map[MAX_BALL][MAX_ROW][MAX_COL];
static int N, W, H;
static int Input_Brick;
static pair<coor, int> Q[MAX_ROW * MAX_COL];
int Qstart, Qend;

inline int Shot(int ball)
{
	int result = 0, temp = 0, curx = 0, cury = 0;

	if (ball > N)
		return 0;
	
	(void)memcpy(&Map[ball][0][0], &Map[ball - 1][0][0], sizeof(Map));

	for (int c = 0; c < W; ++c)
	{
		temp = 0;
		bool check1 = true;
		bool check2 = false;
		for (int r = 0; r < H; ++r)
		{
			if (Map[ball][r][c] > 0)
			{
				check1 = false;
				if (Map[ball][r][c] > 1)
					check2 = true;
				Qstart = 0;
				Qend = 0;
				Q[Qend++] = { {r, c}, Map[ball][r][c] };
				Map[ball][r][c] = 0;
				temp++;
				while (Qstart < Qend)
				{
					int x = Q[Qstart].first.first;
					int y = Q[Qstart].first.second;
					int size = Q[Qstart].second;

					if (Map[ball][x][y] == 1)
						continue;
					for (int d = 0; d < DIRECT; ++d)
					{
						for (int s = 1; s < size; ++s)
						{
							curx = x + (1 * DIR[d][0]);
							cury = y + (1 * DIR[d][1]);
							if (curx < 0 || cury < 0 || curx >= H || cury >= W)
								break;
							if (Map[ball][x][y] == 0)
								continue;
							if (Map[ball][x][y] > 1)
							{
								Q[Qend++] = { {curx, cury}, Map[ball][curx][cury] };
								Map[ball][curx][cury] = 0;
								temp++;
							}
						}
					}
				}
				break;
			}
		}
		if (check1)
			continue;
		if (check2)
		{
			for (int c = 0; c < W; ++c)
			{
				int drop = 0;
				for (int r = H - 1; r >= 0; --r)
				{
					if (Map[ball][r][c] == 0)
						drop++;
					else if (drop)
					{
						curx = r + drop;
						
						int swap_container = Map[ball][r][c];
						Map[ball][r][c] = Map[ball][curx][c];
						Map[ball][curx][c] = swap_container;
					}
				}
			}
		}
		result = max(result, Shot(ball + 1) + temp);
	}
	return result;
}

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

		for (int r = 0; r < H; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin >> Map[0][r][c];
				if (Map[0][r][c] > 0)
					Input_Brick++;
			}
		}
		int Result = Input_Brick - Shot(1);
		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}

