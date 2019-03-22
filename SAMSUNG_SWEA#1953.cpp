//
//	OS Windows
//	2019.03.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1953] <탈주범 검거> (모의 SW 역량테스트)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;

const static int MAX_SIZE = 50;
const static int DIRECT = 4;
const static int PIPE_KIND = 8;

static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };	//동 서 남 북
static int map[MAX_SIZE][MAX_SIZE];
static bool check[MAX_SIZE][MAX_SIZE];
static int N, M, R, C, L;
static queue<coor> Q;
static int result;

void Arrest()
{
	int startQsize, endQsize;
	int count = 1;
	result = 1;
	check[R][C] = true;
	while (!Q.empty())
	{
		if (count > L)
			return;
		else
		{
			
			coor cur = Q.front();
			Q.pop();
			startQsize = Q.size();
			cout << "(" << cur.first << ", " << cur.second << ")" << endl;
			int cur_pipe = map[cur.first][cur.second];
			switch (cur_pipe)
			{
			case 1:	//동서남북
				for (int d = 0; d < DIRECT; ++d)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 0:	//동쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 1:	//서쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 2:	//남쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 3:	//북쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			case 2:	//남북
				for (int d = 2; d < DIRECT; ++d)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 2:	//남쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 3:	//북쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			case 3:	//동서
				for (int d = 0; d < 2; ++d)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 0:	//동쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 1:	//서쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			case 4:	//동북
				for (int d = 0; d < DIRECT; d+=3)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 0:	//동쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 3:	//북쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			case 5:	//동남
				for (int d = 0; d < DIRECT; d+=2)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 0:	//동쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 2:	//남쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			case 6:	//서남
				for (int d = 1; d < 3; ++d)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 1:	//서쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 2:	//남쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			case 7:	//서북
				for (int d = 1; d < DIRECT; d+=2)
				{
					int x = cur.first + dir[d][0];
					int y = cur.second + dir[d][1];
					if (x < 0 || y < 0 || x >= N || y >= M || check[x][y])
						continue;
					else
					{
						switch (d)
						{
						case 1:	//서쪽
							if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						case 3:	//북쪽
							if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6)
							{
								check[x][y] = true;
								Q.push(coor(x, y));
								result++;
							}
							break;
						}
					}
				}
			}
		}
		endQsize = Q.size();
		int addtime = (endQsize - startQsize);
		if (addtime > 1)
			L += addtime;
		count++;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input1953.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		(void)memset(&map[0][0], 0, sizeof(map));
		(void)memset(&check[0][0], false, sizeof(check));
		while (!Q.empty()) { Q.pop(); }

		cin >> N >> M >> R >> C >> L;

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				cin >> map[r][c];
			}
		}

		Q.push(coor(R, C));
		Arrest();
		cout << "#" << test_case << ' ' << result << '\n';
	}
	return 0;
}