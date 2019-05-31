//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1063	킹
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const static int DIRECT = 8;

struct LOC
{
	int row, col;
};

static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
static LOC king, stone;
static int N;
inline void move(int d)
{
	int nr = king.row + dir[d][0];
	int nc = king.col + dir[d][1];
	if (nr > 8 || nr < 1 || nc > 8 || nc < 1)
		return;
	else if (nr == stone.row && nc == stone.col)
	{
		int snr = nr + dir[d][0];
		int snc = nc + dir[d][1];
		if (snr > 8 || snr < 1 || snc > 8 || snc < 1)
			return;
		else
		{
			king.row = nr;
			king.col = nc;
			stone.row = snr;
			stone.col = snc;
		}
	}
	king.row = nr;
	king.col = nc;
}
inline void go(string o)
{
	int d;
	if (o == "R") d = 0;
	else if (o == "L") d = 1;
	else if (o == "B") d = 2;
	else if (o == "T") d = 3;
	else if (o == "RT") d = 4;
	else if (o == "LT") d = 5;
	else if (o == "RB") d = 6;
	else if (o == "LB") d = 7;
	move(d);
}
inline char transform(int c)
{
	char ch = ' ';
	switch (c)
	{
	case 1:
		ch = 'A';
		break;
	case 2:
		ch = 'B';
		break;
	case 3:
		ch = 'C';
		break;
	case 4:
		ch = 'D';
		break;
	case 5:
		ch = 'E';
		break;
	case 6:
		ch = 'F';
		break;
	case 7:
		ch = 'G';
		break;
	case 8:
		ch = 'H';
		break;
	default:
		break;
	}
	return ch;
}
inline void print()
{
	cout << transform(king.col) << king.row << '\n' << transform(stone.col) << stone.row<<'\n';
}
int main(void)
{
	freopen("input1063.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s_king, s_stone, order;
	register int n;
	cin >> s_king >> s_stone >> N;
	king.col = s_king[0] - 'A' + 1;
	king.row = s_king[1] - '0';
	stone.col = s_stone[0] - 'A' + 1;
	stone.row = s_stone[1] - '0';
	for (n = 0; n < N; ++n)
	{
		cin >> order;
		go(order);
	}
	print();
	return 0;
}