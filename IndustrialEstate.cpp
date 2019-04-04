//
//	OS Windows
//	2019.04.04
//
//	[Algorithm Problem Solving]
//
//	<수출산업공단 계획>
//
//	1. 공원 : P, 건물을 지을 수 있는 부지 : B로 입력받음
//	2. 공원에 인접해있는 건물은 1층까지만 올릴 수 있음
//	3. 공원에 인접해있지 않은 건물은 자신을 포함하여 상하좌우의 건물개수만큼 층을 올릴 수 있음
//	4. 모든 건물 높이의 합과 입력받은 높이 이상의 건물 수를 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> coor;
const static int SIZE = 15;
const static int DIRECT = 4;
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static int N, H;
static int map[SIZE][SIZE];
static queue<coor> Q;
static int total_floor, high_floor;

inline void Plan()
{
	while (!Q.empty())
	{
		coor cur = Q.front();
		Q.pop();
		int floor = 1;
		bool flag = true;

		if (cur.first == 1 || cur.first == N - 2 || cur.second == 1 || cur.second == N - 2)
			flag = false;
		else
		{
			for (register int d = 0; d < DIRECT; ++d)
			{
				int x = cur.first + dir[d][0];
				int y = cur.second + dir[d][1];
				if (!map[x][y])
				{
					flag = false;
					break;
				}
			}
		}

		if(flag)
		{
			for (register int r = 1; r < cur.first; ++r)
			{
				if (map[r][cur.second])
					floor++;
			}
			for (register int r = cur.first + 1; r < N - 1; ++r)
			{
				if (map[r][cur.second])
					floor++;
			}
			for (register int c = 1; c < cur.second; ++c)
			{
				if (map[cur.first][c])
					floor++;
			}
			for (register int c = cur.second + 1; c < N - 1; ++c)
			{
				if (map[cur.first][c])
					floor++;
			}
		}

		map[cur.first][cur.second] = floor;
		total_floor += floor;
		if (floor >= H)
			high_floor++;
	}
}

int main(int argc, char** argv)
{
	freopen("testcase_IndustrialEstate.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		total_floor = 0; high_floor = 0;
		cin >> N >> H;
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				char input;
				cin >> input;
				switch (input)
				{
				case 'P':
					map[r][c] = 0;
					break;
				case 'B':
					map[r][c] = 1;
					Q.push({ r, c });
					break;
				}
			}
		}
		Plan();
		cout << "#" << test_case << ' ' << total_floor << ' ' << high_floor << '\n';
		
	}
	return 0;
}