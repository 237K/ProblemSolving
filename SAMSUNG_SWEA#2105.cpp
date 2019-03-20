//
//	OS Windows
//	2019.03.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2105] <디저트 카페>
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const static int MAP_SIZE = 20;
const static int MAX_KIND = 101;

static int N;
static int Map[MAP_SIZE][MAP_SIZE];
static int DirRow[4] = { 1, 1, -1, -1 };
static int DirCol[4] = { -1, 1, 1, -1 };
bool Check[MAX_KIND];

int Go()
{
	int Result = -1;
	for (int Path = N - 1; Path > 1; --Path)
	{
		for (int Start_row = 0; Start_row < N - Path; ++Start_row)
		{
			for (int Start_col = 0; Start_col < N - Path; ++Start_col)
			{
				for (int Check_next_col = Start_col + 1; Check_next_col < Start_col + Path; ++Check_next_col)
				{
					int dir = 0;
					int row = Start_row;
					int col = Check_next_col;
					(void)memset(&Check[0], false, sizeof(Check));
					while (1)
					{
						if (dir == 3 && row == Start_row && col == Check_next_col)
						{
							Result = Path * 2;
							return Result;
						}
						else if (row + DirRow[dir] >= Start_row
							&& row + DirRow[dir] <= Start_row + Path 
							&& col + DirCol[dir] >= Start_col 
							&& col + DirCol[dir] <= Start_col + Path)
						{
							row += DirRow[dir];
							col += DirCol[dir];
							if (!Check[Map[row][col]])
							{
								Check[Map[row][col]] = true;
							}
							else
								break;
						}
						else
						{
							dir++;
						}
					}
				}
			}
		}
	}
	return Result;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input2105.txt", "r", stdin);
	int T;
	int test_case;
	//scanf("%d", &T);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0;
		(void)memset(&Map[0][0], 0, sizeof(Map));

		//scanf("%d", &N);
		cin >> N;
		for (int row = 0; row < N; ++row)
		{
			for (int col = 0; col < N; ++col)
			{
				//scanf("%d", &Map[row][col]);
				cin >> Map[row][col];
			}
		}

		cout << "#" << test_case << ' ' << Go() << '\n';

	}
	return 0;
}
