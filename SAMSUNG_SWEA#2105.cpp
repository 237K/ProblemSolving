//
//	OS Windows
//	2019.03.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2105] <����Ʈ ī��>
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> coor;
const static int MAP_SIZE = 20;
static int N;
static int Map[MAP_SIZE][MAP_SIZE];
static bool Check[MAP_SIZE][MAP_SIZE];
static vector<int> Route;				//��ο��� ���� ���ڰ� �־����� Ȯ���ϱ� ����
static stack<coor> Stack;
static int Result;

void DFS(int r, int c)
{
	int temp = 0;
	temp += Map[r][c];
	Route.push_back(Map[r][c]);
	if (r == N - 3 && c == N - 1)
	{
		return;
	}
	else
	{
		if (r + 1 < N && c + 1 < N && Check[r + 1][c + 1] == false)
		{

		}
		else if (r + 1 < N && c - 1 >= 0 && Check[r + 1][c - 1] == false)
		{

		}
		else if (r - 1 >= 0 && c - 1 >= 0 && Check[r - 1][c - 1] == false)
		{

		}
		else if (r - 1 >= 0 && c + 1 < N && Check[r - 1][c + 1] == false)
		{

		}
	}

}

int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("s_input2105.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0;
		Result = -2147000000;
		Route.clear();
		while (!Stack.empty()) { Stack.pop(); }
		for (int row = 0; row < N; ++row)
		{
			for (int col = 0; col < N; ++col)
			{
				Map[row][col] = 0;
				Check[row][col] = false;
			}
		}

		scanf("%d", &N);
		for (int row = 0; row < N; ++row)
		{
			for (int col = 0; col < N; ++col)
			{
				scanf("%d", &Map[row][col]);
			}
		}
	}
	return 0;
}
