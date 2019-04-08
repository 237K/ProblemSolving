//
//	OS Windows
//	2019.04.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2806> N-Queen (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int DIRECT = 8;
const static int SIZE = 10;
static int dir[DIRECT][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
static int map[SIZE][SIZE];
static int check[SIZE];
static int N;
static int result;

//행과 열은 검사안해도 되긴 하지만, 혹시 몰라서 8방향 다 검사해봄
inline bool possible(int row, int col)
{
	for (register int d = 0; d < DIRECT; ++d)
	{
		for (register int n = 1; n < N; ++n)
		{
			int r = row + (n * dir[d][0]);
			int c = col + (n * dir[d][1]);
			if (r < 0 || c < 0 || r >= N || c >= N)
				continue;
			if (map[r][c])
				return false;
		}
	}
	return true;
}

//DFS로 생각해봄
//각 행에는 퀸을 하나 밖에 놓을 수 없으므로 N개의 퀸은 반드시 N개의 행에 하나씩 놓아야됨. 
//퀸을 하나 놓으면 경우의 수가 기하급수적으로 줄어드므로 N이 커져도 실행시간은 크게 늘어나지 않을 것
inline void N_Queen(int count)
{
	//퀸을 N개 놓으면 경우의수 +1
	//퀸을 N개 놓지 못하면 N-1개로 돌아가서 다른 자리에 놔보고 안되면 N-2개로 돌아가서 다른자리에 놔보고........반복
	if (count == N)
	{
		result++;
		return;
	}
	else
	{
		for (register int c = 0; c < N; ++c)
		{
			//이 열을 이미 체크했으면 넘어가고
			if (check[c])
				continue;
			//이 열을 이전에 체크하지 않았고, 이 자리에 다른 퀸이 없고, 8방향으로 모두 퀸이 없으면
			if (!map[count][c] && possible(count, c))
			{
				//여기에 퀸을 놓고 다음 행으로 넘어가서 퀸을 8개 모두 놓을 수 있으면 경우의수 +1
				check[c]++;
				map[count][c]++;
				N_Queen(count + 1);
				check[c] = 0;
				map[count][c] = 0;
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input2806.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		(void)memset(check, 0, sizeof(check));
		result = 0;
		cin >> N;
		N_Queen(0);
		cout << "#" << test_case << ' ' << result << '\n';
	}
	return 0;
}