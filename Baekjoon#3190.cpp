//
//	OS Windows
//	2019.04.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3190	��
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int, char> time_and_order;
const static int SIZE = 101;
const static int DIRECT = 4;

static int apple[SIZE][SIZE];
static int time_table[SIZE][SIZE];
static int N, K, L;
static time_and_order order[SIZE];
static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int snake_cur_row, snake_cur_col, snake_cur_dir, snake_cur_len;

inline void init()
{
	(void)memset(apple, 0, sizeof(apple));
	(void)memset(time_table, 0, sizeof(time_table));
	snake_cur_row = 1;
	snake_cur_col = 1;
	snake_cur_dir = 0;
	snake_cur_len = 1;
}
inline void change_direction(int o)
{
	switch (o)
	{
	case 'L':
		snake_cur_dir = (snake_cur_dir + 3) % DIRECT;
		break;
	case 'D':
		snake_cur_dir = (snake_cur_dir + 1) % DIRECT;
		break;
	default:
		break;
	}
}
inline int go()
{
	int time = 0;
	while (1)
	{
		time++;
		//	�ʱ� ��ġ�� 1, 1�̰� ������ ������(0)
		//
		int nr = snake_cur_row + dir[snake_cur_dir][0];
		int nc = snake_cur_col + dir[snake_cur_dir][1];
		//	�������� 1. ���� �ε����� ��
		if (nr < 1 || nc < 1 || nr > N || nc > N)
			break;

		//	�������� 2. �ڽ��� ���뿡 �ε����� ��
		if (snake_cur_len > 3 && time_table[nr][nc] && time_table[nr][nc] >= time_table[snake_cur_row][snake_cur_col] - snake_cur_len + 1)
			break;

		//	�Ӹ� �̵�
		snake_cur_row = nr;
		snake_cur_col = nc;
		time_table[nr][nc] = time;
		//	��� ������ ����++
		if (apple[nr][nc] == 1)
		{
			snake_cur_len++;
			apple[nr][nc] = 0;
		}

		//	��ɾ� �迭 �ѷ����� ���� �ð��� �����ؾ��ϴ� ��ɾ� ������ ����
		bool is_there_order = false;
		char this_time_order = ' ';
		for (register int i = 0; i < L; ++i)
		{
			if (!order[i].first)
				continue;
			else if (order[i].first == time)
			{
				this_time_order = order[i].second;
				order[i].first = 0;
				is_there_order = true;
				break;
			}
		}
		if (is_there_order)
			change_direction(this_time_order);
	}
	return time;
}

int main(int argc, char** argv)
{
	freopen("input3190.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	init();
	cin >> N;
	cin >> K;
	for (register int a = 0; a < K; ++a)
	{
		int r = 0, c = 0;
		cin >> r >> c;
		apple[r][c] = 1;
	}
	cin >> L;
	for (register int l = 0; l < L; ++l)
	{
		int t = 0;
		char o = ' ';
		cin >> t >> o;
		order[l] = { t, o };
	}
	cout << go();
	return 0;
}