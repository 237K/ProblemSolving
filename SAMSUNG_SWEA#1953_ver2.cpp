//
//	OS Windows
//	2019.04.13
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1953] <탈주범 검거> (모의 SW 역량테스트)
//	
//	ver2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> coor;

const static int SIZE = 50;
const static int DIRECT = 4;
const static int PIPE = 8;

static int dir[DIRECT][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
static int pipeline[PIPE][DIRECT][PIPE] = { { {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 0, 0, 0, 0, 0, 0, 0 }},
	
											{ {0, 1, 1, 0, 0, 1, 1, 0},
											  {0, 1, 1, 0, 1, 0, 0, 1},
											  {0, 1, 0, 1, 1, 1, 0, 0},
											  {0, 1, 0, 1, 0, 0, 1, 1}},

											{ {0, 1, 1, 0, 0, 1, 1, 0 },
											  {0, 1, 1, 0, 1, 0, 0, 1 },
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 0, 0, 0, 0, 0, 0, 0 }},

											{ {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 1, 0, 1, 1, 1, 0, 0 },
											  {0, 1, 0, 1, 0, 0, 1, 1 }},

											{ {0, 1, 1, 0, 0, 1, 1, 0},
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 1, 0, 1, 0, 0, 1, 1 }},

											{ {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 1, 1, 0, 1, 0, 0, 1},
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 1, 0, 1, 0, 0, 1, 1}},

											{ {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 1, 1, 0, 1, 0, 0, 1},
											  {0, 1, 0, 1, 1, 1, 0, 0},
											  {0, 0, 0, 0, 0, 0, 0, 0 }},

											{ {0, 1, 1, 0, 0, 1, 1, 0},
											  {0, 0, 0, 0, 0, 0, 0, 0 },
											  {0, 1, 0, 1, 1, 1, 0, 0},
											  {0, 0, 0, 0, 0, 0, 0, 0 }} };
static int map[SIZE][SIZE];
static int check[SIZE][SIZE];
static int route[SIZE][SIZE];
static queue<coor> Q;
static int N, M, R, C, L;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, 0, sizeof(check));
	(void)memset(route, 0, sizeof(route));
	while (!Q.empty()) { Q.pop(); }
}
inline int search()
{
	int result = 0;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			if (route[r][c] && route[r][c] <= L)
				result++;
		}
	}
	return result;
}
inline int simulation()
{
	Q.push({ R, C });
	check[R][C] = 1;
	route[R][C] = 1;
	while (!Q.empty())
	{
		coor cur = Q.front();
		Q.pop();
		int cur_pipe = map[cur.first][cur.second];
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nr = cur.first + dir[d][0];
			int nc = cur.second + dir[d][1];
			int n_pipe = map[nr][nc];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M || check[nr][nc])
				continue;
			if (!pipeline[cur_pipe][d][n_pipe])
				continue;
			Q.push({ nr, nc });
			check[nr][nc] = 1;
			route[nr][nc] = route[cur.first][cur.second] + 1;
		}
	}
	return search();
}
int main(int argc, char** argv)
{
	freopen("s_input1953.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M >> R >> C >> L;
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < M; ++c)
			{
				cin >> map[r][c];
			}
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}