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
using namespace std;
typedef pair<int, int> coor;
const static int SIZE = 50;
const static int DIRECT = 4;

static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SIZE][SIZE];
static int N, M;
//inline void print(int r, int c)
//{
//	int temp = map[r][c];
//	map[r][c] = 8;
//	for (register int r = 0; r < N; ++r)
//	{
//		for (register int c = 0; c < M; ++c)
//		{
//			cout << map[r][c] << "   ";
//		}
//		cout << "\n\n";
//	}
//	cout << "\n\n";
//	map[r][c] = temp;
//}
inline bool search(int r, int c, int d)
{
	int cr = r, cc = c;
	int nr = cr + dir[d][0];
	int nc = cc + dir[d][1];
	if (nr < 0 || nc < 0 || nr >= N || nc >= M)
		return false;
	if (!map[nr][nc])
		return true;
	return false;
}
inline int simulation(int sr, int sc, int sd)
{
	int result = 0;
	int cr = sr, cc = sc, cd = sd;
	while (1)
	{
		int back_flag = 0;
		//	현재 위치 청소
		if (!map[cr][cc])
		{
			result++;
			map[cr][cc] = -1;
		}
		//print(cr, cc);
		//	현재 위치를 기준으로 왼쪽으로 90도씩 회전하면서 4방향 검사
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nd = (cd + 3) % 4;
			int nr = cr + dir[nd][0];
			int nc = cc + dir[nd][1];
			//	벽인지 검사
			if (map[nr][nc] == 1)
			{
				back_flag++;
				cd = nd;
				continue;
			}
			//	벽이 아니면 그 방향에 청소할 곳이 있는지 검사
			if (search(cr, cc, nd))
			{
				//	이동할 수 있고 청소할 곳이 있으면 그 방향으로 회전하고 이동
				back_flag = 0;
				cr = nr;
				cc = nc;
				cd = nd;
				break;
			}
			//	벽은 아닌데 청소할 곳이 없으면
			else
			{
				cd = nd;
				back_flag++;
				continue;
			}
		}
		//	4방향 다 벽이거나 청소할 곳이 없으면
		if (back_flag == 4)
		{
			int bnd = (cd + 2) % 4;
			int bnr = cr + dir[bnd][0];
			int bnc = cc + dir[bnd][1];
			//	후진할 수 있는지 검사하고, 뒷쪽도 벽이면 종료
			if (map[bnr][bnc] == 1)
				break;
			//	뒷쪽이 벽이 아니면 방향은 바꾸지 않고 한 칸 후진
			else
			{
				back_flag = 0;
				cr = bnr;
				cc = bnc;
			}
		}
	}
	return result;
}
int main(int argc, char** argv)
{
	freopen("input14503.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _sr, _sc, _sd;
	register int r, c;
	cin >> N >> M;
	cin >> _sr >> _sc >> _sd;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << simulation(_sr, _sc, _sd);
	return 0;
}