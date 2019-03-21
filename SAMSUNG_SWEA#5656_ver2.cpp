//
//	OS Windows
//	2019.03.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5656] <벽돌 깨기> (모의 SW 역량테스트)
//	ver1. 시간초과	
//	ver2. Pass
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
static pair<coor, int> Q[MAX_ROW * MAX_COL];	//벽돌 깨나갈 때 사용할 큐. 좌표와 벽돌의 파괴력을 쌍으로 저장
static int Qstart, Qend;						//그냥 Q 써도 무방

inline void PrintMap()							//제대로 작동하는지 확인해보기 위함
{
	for (int r = 0; r < H; ++r)
	{
		for (int c = 0; c < W; ++c)
		{
			cout << Map[0][r][c] << ' ';
		}
		cout << "\n\n";
	}
}

inline int Shot(int ball)		//DFS (재귀)
{
	if (ball > N)				//재귀 탈출 조건
		return 0;
	
	else
	{							//동작 부분
		int result = 0;			//이때까지 파괴된 벽돌 수 저장 (완전탐색하고 제일 많이 파괴한 경우의 파괴한 벽돌 수 반환)
		int temp;				//이번에 쏜 구슬로 파괴된 벽돌 수 저장
		int curx, cury;			//벽돌 깨나갈 때, 빈 곳 채울 때 좌표 저장하기 위한 변수

		for (int c = 0; c < W; ++c)
		{
			for (int cpy = 0; cpy < H; ++cpy)
				(void)memcpy(Map[ball][cpy], Map[ball - 1][cpy], sizeof(int)*W);	//이전에 쏜 구슬로 벽돌 파괴된거 반영된 맵 복사해옴
			temp = 0;
			bool check1 = true;					//벽돌이 0인 경우 확인하기 위함
			bool check2 = false;				//벽돌 파괴력이 1보다 큰 경우 확인하기 위함
			for (int r = 0; r < H; ++r)
			{
				if (Map[ball][r][c])			//0이 아닌 벽돌 만나면
				{
					check1 = false;				
					if (Map[ball][r][c] > 1)	//벽돌 파괴력이 1 보다 크면
						check2 = true;			//체크해둠
					Qstart = 0;
					Qend = 0;
					Q[Qend++] = { {r, c}, Map[ball][r][c] };	//큐에 저장
					Map[ball][r][c] = 0;						//해당 벽돌 파괴
					temp++;										//파괴한 벽돌 수 + 1
					while (Qstart < Qend)						//큐가 빌 때 까지 while(!Q.empty())
					{
						int x = Q[Qstart].first.first;			//Q.pop()
						int y = Q[Qstart].first.second;
						int size = Q[Qstart++].second;

						if (Map[ball][x][y] == 1)
							continue;

						for (int d = 0; d < DIRECT; ++d)		//동서남북 순으로
						{
							for (int s = 1; s < size; ++s)		//파괴력 만큼
							{
								curx = x + (s * DIR[d][0]);		
								cury = y + (s * DIR[d][1]);
								if (curx < 0 || cury < 0 || curx >= H || cury >= W)		
									break;
								if (Map[ball][curx][cury] == 0)
									continue;
								if (Map[ball][curx][cury] > 1)	//파괴력이 1보다 크면
								{
									Q[Qend++] = { {curx, cury}, Map[ball][curx][cury] };	//큐에 넣고
								}
								Map[ball][curx][cury] = 0;		//해당 벽돌 파괴
								temp++;							//파괴한 벽돌 수 + 1
							}
						}
					}
					break;				
				}
			}
			//파괴하고나서 비어있는부분 채움
			if (check1)
				continue;
			if (check2)
			{
				for (int dropc = 0; dropc < W; ++dropc)
				{
					int drop = 0;
					for (int dropr = H - 1; dropr >= 0; --dropr)
					{
						if (Map[ball][dropr][dropc] == 0)
							drop++;
						else if (drop)
						{
							curx = dropr + drop;

							int swap_container = Map[ball][dropr][dropc];
							Map[ball][dropr][dropc] = Map[ball][curx][dropc];
							Map[ball][curx][dropc] = swap_container;
						}
					}
				}
			}
			result = max(result, Shot(ball + 1) + temp);
		}
		return result;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> W >> H;
		int Result = 0;
		int Input_Brick = 0;
		for (int r = 0; r < H; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin >> Map[0][r][c];
				if (Map[0][r][c] > 0)
					Input_Brick++;				//벽돌 몇개인지 세고
			}
		}
		
		Result = Input_Brick - Shot(1);			//입력받은 벽돌 개수에서 제일 많이 파괴했을 때의 벽돌 수 뺌
		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}

