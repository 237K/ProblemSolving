//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2174	·Îº¿ ½Ã¹Ä·¹ÀÌ¼Ç
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int DIRECT = 4;
const static int MAX = 101;

struct ROBOT
{
	int r, c, d;
};
static int dir[DIRECT][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
static int A, B, N, M;
static int map[MAX][MAX];
static ROBOT robot[MAX];

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	for (register int i = 0; i < MAX; ++i)
	{
		robot[i] = { 0, 0, 0 };
	}
}
inline int change_dir(char ch)
{
	int nd = 0;
	switch (ch)
	{
	case 'N':
		nd = 0;
		break;
	case 'E':
		nd = 1;
		break;
	case 'S':
		nd = 2;
		break;
	case 'W':
		nd = 3;
		break;
	default:
		break;
	}
	return nd;
}
inline bool execution(int robot_idx, char inst, int num)
{
	ROBOT cur = robot[robot_idx];
	if (inst == 'L')
	{
		int n = num % 4;
		robot[robot_idx].d = (cur.d + (3*n)) % 4;
		return true;
	}
	else if (inst == 'R')
	{
		int n = num % 4;
		robot[robot_idx].d = (cur.d + n) % 4;
		return true;
	}
	else if (inst == 'F')
	{
		map[cur.r][cur.c] = 0;
		while (num--)
		{
			int nr = cur.r + dir[cur.d][0];
			int nc = cur.c + dir[cur.d][1];
			if (nr < 1 || nc < 1 || nr > B || nc > A)
			{
				cout << "Robot " << robot_idx << " crashes into the wall";
				return false;
			}
			else if (map[nr][nc])
			{
				for (register int i = 1; i <= N; ++i)
				{
					if (robot[i].r == nr && robot[i].c == nc)
					{
						cout << "Robot " << robot_idx << " crashes into robot " << i;
						return false;
					}
				}
			}
			else
			{
				cur.r = nr;
				cur.c = nc;
			}
		}
		robot[robot_idx].r = cur.r;
		robot[robot_idx].c = cur.c;
		map[cur.r][cur.c] = 1;
	}
	cout << "inst : " << inst << " (" << cur.r << ", " << cur.c << ") d : " << cur.d << '\n';
	return true;
}
int main(void)
{
	freopen("input2174.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int x, y, order_robot, order_num;
	char direct, order_inst;
	bool flag = true;
	register int n, m;
	cin >> A >> B;
	cin >> N >> M;
	for (n = 1; n <= N; ++n)
	{
		cin >> x >> y >> direct;
		map[y][x] = 1;
		robot[n] = { y, x, change_dir(direct) };
	}
	for (m = 0; m < M; ++m)
	{
		cin >> order_robot >> order_inst >> order_num;
		if (!execution(order_robot, order_inst, order_num))
		{
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "OK";
	return 0;
}