//
//	OS Windows
//	2019.05.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1018	체스판 다시 칠하기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int SIZE = 50;
const static int BOARD = 8;
static int chess_board[2][BOARD][BOARD] =
{ { 0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0 },
	{ 1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1 } };
static int map[SIZE][SIZE];
static int N, M;
//inline void print(int r, int c)
//{
//	cout << "(" << r << ", " << c << ")\n";
//	for (register int row = r; row < r + BOARD; ++row)
//	{
//		for (register int col = c; col < c + BOARD; ++col)
//		{
//			cout << map[row][col] << ' ';
//		}
//		cout << "\n\n";
//	}
//}
inline int check(int r, int c, int start)
{
	int cnt = 0, cnt2 = 64, comp_r = 0, comp_c = 0;
	for (register int row = r; row < r + BOARD; ++row)
	{
		comp_c = 0;
		for (register int col = c; col < c + BOARD; ++col)
		{
			if (map[row][col] != chess_board[start][comp_r][comp_c++])
				cnt++;
		}
		comp_r++;
	}
	//print(r, c);
	//cout << "cnt : " << cnt << "\n\n";
	cnt2 -= cnt;
	if (cnt > cnt2) cnt = cnt2;
	return cnt;
}
inline int simulation()
{
	int ret = 64;
	int temp = 0;
	for (register int r = 0; r <= N - BOARD; ++r)
	{
		for (register int c = 0; c <= M - BOARD; ++c)
		{
			temp = check(r, c, map[r][c]);
			if (temp == -1) continue;
			if (ret > temp) ret = temp;
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input1018.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	char in;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> in;
			if (in == 'W') map[r][c] = 0;
			else map[r][c] = 1;
		}
	}
	cout << simulation();
	return 0;
}