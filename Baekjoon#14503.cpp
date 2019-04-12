//
//	OS Windows
//	2019.04.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14503	로봇 청소기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> coor;
typedef pair<coor, int> coor_and_dir;

const static int SIZE = 51;
const static int DIRECT = 4;

static int map[SIZE][SIZE];
static int check[SIZE][SIZE];
static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int N, M, x, y, start_direct;
static queue<coor_and_dir> Q;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, 0, sizeof(check));
}
inline bool search_left(int cur_r, int cur_c, int cur_d)
{
	//	현재 방향이 북쪽이면 서쪽 탐색
	if (cur_d == 0)
	{
		for (register int c = cur_c; c >= 0; --c)
		{
			if (!map[cur_r][c] && !check[cur_r][c])
				return true;
		}
	}
	//	현재 방향이 동쪽이면 북쪽 탐색
	else if (cur_d == 1)
	{
		for (register int r = cur_r; r >= 0; --r)
		{
			if (!map[r][cur_c] && !check[r][cur_c])
				return true;
		}
	}
	//	현재 방향이 남쪽이면 동쪽 탐색
	else if (cur_d == 2)
	{
		for (register int c = cur_c; c < M; ++c)
		{
			if (!map[cur_r][c] && !check[cur_r][c])
				return true;
		}
	}
	//	현재 방향이 서쪽이면 남쪽 탐색
	else if (cur_d == 3)
	{
		for (register int r = cur_r; r < N; ++r)
		{
			if (!map[r][cur_c] && !check[r][cur_c])
				return true;
		}
	}
	return false;
}
inline int go()
{
	Q.push({ {x, y}, start_direct });
	//	시작위치는 청소하고 시작
	check[x][y] = 1;
	int result = 1;

	int end_flag = 0;
	while (!Q.empty())
	{
		coor_and_dir cur = Q.front();
		Q.pop();
		int cr = cur.first.first;
		int cc = cur.first.second;
		int cd = cur.second;

		//	왼쪽에 청소할 곳이 있든 없든 로봇청소기 방향은 왼쪽으로 회전함
		int nd = (cd + 3) % 4;

		//	왼쪽에 청소할 곳이 있는지 탐색해보고
		//	청소할 곳이 있으면 왼쪽으로 회전하고 한 칸 전진함.
		if (search_left(cr, cc, cd))
		{
			int nr = cr + dir[nd][0];
			int nc = cc + dir[nd][1];
			//	만약 벽이 있으면 방향은 유지한채로 한 칸 후진함
			if (map[nr][nc])
			{
				int back_dir = (nd + 2) % 4;
				int nnr = nr + dir[back_dir][0];
				int nnc = nc + dir[back_dir][1];
				//	후진도 못하면 그자리에서 왼쪽으로 또 회전
				if (map[nnr][nnc])
				{
					int nnd = (nd + 3) % 4;
					Q.push({ {cr, cc}, nnd });
					end_flag++;
					continue;
				}
				//	후진 **후진했을 경우 청소는 안함!
				else if (!map[nnr][nnc])
				{
					Q.push({ {nnr, nnc}, nd });
					end_flag = 0;
					continue;
				}
			}
			//	한 칸 전진하고, 여기 청소안했으면 청소하고 체크함
			else
			{
				Q.push({ {nr, nc}, nd });
				if (!check[nr][nc])
				{
					check[nr][nc] = 1;
					result++;
				}
				end_flag = 0;
			}
		}
		//	청소할 곳이 없으면 그자리에서 회전만 함
		else
		{
			Q.push({ {cr, cc}, nd });
			end_flag++;
		}
		if (end_flag == 4)
			return result;
	}
	return result;
}

int main(int argc, char** argv)
{
	freopen("input14503.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	init();
	cin >> N >> M;
	cin >> x >> y >> start_direct;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << go();
	return 0;
}