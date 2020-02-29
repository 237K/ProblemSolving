//
//	OS Windows
//	2020.02.19
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #14499>	주사위 굴리기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int SZ = 21;
const static int DICE = 6;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
static int board[SZ][SZ], dice[DICE], N, M, K, x, y, order;
inline void swap(int idx1, int idx2)
{
	register int tmp;
	tmp = dice[idx1];
	dice[idx1] = dice[idx2];
	dice[idx2] = tmp;
}
inline void go_east()
{
	swap(0, 2);
	swap(2, 3);
	swap(2, 5);
}
inline void go_west()
{
	swap(0, 3);
	swap(2, 3);
	swap(3, 5);
}
inline void go_north()
{
	swap(0, 1);
	swap(1, 5);
	swap(4, 5);
}
inline void go_south()
{
	swap(0, 1);
	swap(0, 4);
	swap(4, 5);
}
inline int out_check(int o)
{
	register int nr, nc;
	nr = x + dir[o][0];
	nc = y + dir[o][1];
	if (nr < 0 || nr >= N || nc < 0 || nc >= M) return 0;
	x = nr;
	y = nc;
	return 1;
}
inline void move(int o)
{
	if (!o) go_east();
	else if (o == 1) go_west();
	else if (o == 2) go_north();
	else go_south();
}
inline void copy()
{
	if (!board[x][y]) 
		board[x][y] = dice[5];
	else
	{
		dice[5] = board[x][y];
		board[x][y] = 0;
	}
}
inline void print()
{
	cout << dice[0] << '\n';
}
int main(int argc, char** argv)
{
	freopen("input14499.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(dice, 0, sizeof(dice));
	register int r, c, k;
	cin >> N >> M >> x >> y >> K;
	for (r = 0; r < N; ++r)
		for (c = 0; c < M; ++c)
			cin >> board[r][c];
	for (k = 0; k < K; ++k)
	{
		cin >> order;
		order -= 1;
		if (!out_check(order)) continue;
		move(order);
		copy();
		print();
	}
	return 0;
}