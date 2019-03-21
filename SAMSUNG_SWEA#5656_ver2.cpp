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
static pair<coor, int> Q[MAX_ROW * MAX_COL];


int main(int argv, char** argc)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	int N, W, H;
	cin >> T;
	//scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0, W = 0, H = 0;
		cin >> N >> W >> H;
		//scanf("%d %d %d", &N, &W, &H);

		for (int r = 0; r < H; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin >> test.Map[0][r][c];
				//scanf("%d", &test.Map[0][r][c]);
				if (test.Map[0][r][c] > 0)
					test.Input_Num_Brick++;
			}
		}
		cout << "#" << test_case << ' ' << test.Simulation() << '\n';
		//printf("#%d %d\n", test_case, test.Simulation());
	}
	return 0;
}

