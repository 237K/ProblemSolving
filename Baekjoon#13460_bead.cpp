//
//	OS Windows
//	2019.04.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #13460	���� Ż��2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair<int, int> coor;
const static int SIZE = 10;
const static int DIRECT = 4;
const static int INF = 11;

static int dir[DIRECT][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
static char map[SIZE][SIZE];
static int N, M;
static vector<coor> R_bead;
static vector<coor> B_bead;
static coor hole;
static int result;

inline void init()
{
	result = INF;
}
//	������ ���� �� Ȥ�� ���� ���� �ִ���, �׷��ٸ� ��� ��ġ���ִ��� Ȯ��
//	return 0 : ���� ��/���� ���� ����
//	return 1 : ���� ��/���� �ְ� R�� �ռ�����. �ռ��ִٴ� ���� �����̴� ������ �������� �ռ��ִٴ� ��.
//	return 2 : ���� ��/���� �ְ� B�� �ռ�����
inline int east_near_RB(int cnt)
{
	if (R_bead[cnt].first == B_bead[cnt].first)
	{
		if (R_bead[cnt].second > B_bead[cnt].second)
			return 1;
		else
			return 2;
	}
	else
		return 0;
}
inline int west_near_RB(int cnt)
{
	if (R_bead[cnt].first == B_bead[cnt].first)
	{
		if (R_bead[cnt].second < B_bead[cnt].second)
			return 1;
		else
			return 2;
	}
	else
		return 0;
}
inline int south_near_RB(int cnt)
{
	if (R_bead[cnt].second == B_bead[cnt].second)
	{
		if (R_bead[cnt].second > B_bead[cnt].second)
			return 1;
		else
			return 2;
	}
	else
		return 0;
}
inline int north_near_RB(int cnt)
{
	if (R_bead[cnt].second == B_bead[cnt].second)
	{
		if (R_bead[cnt].second < B_bead[cnt].second)
			return 1;
		else
			return 2;
	}
	else
		return 0;
}
//	���� �̵�
//	�����ʿ� ������ ������ ���� ��ǥ�� �̵� -> ����Լ��� ���ư��� �������ǿ� ���� ����
//	���� ������ �� �ڿ��� ����
//	�ռ��ִ� ������ ������ ���� �ڿ� ����
inline void go_east(int cnt)
{
	int temp = east_near_RB(cnt);
	int R_row = R_bead[cnt].first;
	int B_row = B_bead[cnt].first;
	int flag_hole = 0;
	int flag_wall = 0;
	//	�������� ���� ��/���� ���� ���� ���
	if (!temp)
	{
		//	�������� �̵�
		for (register int i = R_bead[cnt].second; i < N; ++i)
		{
			if (map[R_row][i] == '.')
				continue;
			if (map[R_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[R_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		//���ۿ� ���� �����Ƿ�, �Ķ������� ������ �ʿ� ������ ����
		if (flag_hole)
		{
			R_bead.push_back({ R_row, flag_hole });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ R_row, flag_wall - 1 });
		}
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].second; i < N; ++i)
		{
			if (map[B_row][i] == '.')
				continue;
			if (map[B_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[B_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ B_row, flag_hole });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ B_row, flag_wall - 1 });
		}
	}
	//	�������� ���� �࿡ �ִµ� R�� �ռ��ִ� ��� -> R�� ���� ������
	if (temp == 1)
	{
		//	�������� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = R_bead[cnt].second; i < N; ++i)
		{
			if (map[R_row][i] == '.')
				continue;
			if (map[R_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[R_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			R_bead.push_back({ R_row, flag_hole });
			//	�Ķ����� �̵�
			B_bead.push_back({ B_row, flag_hole - 1 });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ R_row, flag_wall - 1 });
			//	�Ķ����� �̵�
			B_bead.push_back({ B_row, flag_wall - 1 });
		}
	}
	//	�������� ���� �࿡ �ִµ� B�� �ռ��ִ� ��� -> B�� ���� ������
	if (temp == 2)
	{
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].second; i < N; ++i)
		{
			if (map[B_row][i] == '.')
				continue;
			if (map[B_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[B_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ B_row, flag_hole });
			//	�������� �̵�
			R_bead.push_back({ R_row, flag_hole - 1 });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ B_row, flag_wall - 1 });
			//	�������� �̵�
			R_bead.push_back({ R_row, flag_wall - 1 });
		}
	}
}

inline void go_west(int cnt)
{
	int temp = west_near_RB(cnt);
	int R_row = R_bead[cnt].first;
	int B_row = B_bead[cnt].first;
	int flag_hole = 0;
	int flag_wall = 0;
	//	�������� ���� ��/���� ���� ���� ���
	if (!temp)
	{
		//	�������� �̵�
		for (register int i = R_bead[cnt].second; i >= 0; --i)
		{
			if (map[R_row][i] == '.')
				continue;
			if (map[R_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[R_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		//���ۿ� ���� �����Ƿ�, �Ķ������� ������ �ʿ� ������ ����
		if (flag_hole)
		{
			R_bead.push_back({ R_row, flag_hole });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ R_row, flag_wall + 1 });
		}
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].second; i >= 0; --i)
		{
			if (map[B_row][i] == '.')
				continue;
			if (map[B_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[B_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ B_row, flag_hole });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ B_row, flag_wall + 1 });
		}
	}
	//	�������� ���� �࿡ �ִµ� R�� �ռ��ִ� ��� -> R�� ���� ������
	if (temp == 1)
	{
		//	�������� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = R_bead[cnt].second; i >= 0; --i)
		{
			if (map[R_row][i] == '.')
				continue;
			if (map[R_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[R_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			R_bead.push_back({ R_row, flag_hole });
			//	�Ķ����� �̵�
			B_bead.push_back({ B_row, flag_hole + 1 });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ R_row, flag_wall + 1 });
			//	�Ķ����� �̵�
			B_bead.push_back({ B_row, flag_wall + 2 });
		}
	}
	//	�������� ���� �࿡ �ִµ� B�� �ռ��ִ� ��� -> B�� ���� ������
	if (temp == 2)
	{
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].second; i >= 0; --i)
		{
			if (map[B_row][i] == '.')
				continue;
			if (map[B_row][i] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[B_row][i] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ B_row, flag_hole });
			//	�������� �̵�
			R_bead.push_back({ R_row, flag_hole + 1 });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ B_row, flag_wall + 1 });
			//	�������� �̵�
			R_bead.push_back({ R_row, flag_wall + 2 });
		}
	}
}

inline void go_south(int cnt)
{
	int temp = south_near_RB(cnt);
	int R_col = R_bead[cnt].second;
	int B_col = B_bead[cnt].second;
	int flag_hole = 0;
	int flag_wall = 0;
	//	�������� ���� ��/���� ���� ���� ���
	if (!temp)
	{
		//	�������� �̵�
		for (register int i = R_bead[cnt].first; i < N; ++i)
		{
			if (map[i][R_col] == '.')
				continue;
			if (map[i][R_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][R_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		//���ۿ� ���� �����Ƿ�, �Ķ������� ������ �ʿ� ������ ����
		if (flag_hole)
		{
			R_bead.push_back({ flag_hole, R_col });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ flag_wall - 1, R_col });
		}
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].first; i < N; ++i)
		{
			if (map[i][B_col] == '.')
				continue;
			if (map[i][B_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][B_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ flag_hole, B_col });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ flag_wall - 1 , B_col });
		}
	}
	//	�������� ���� �࿡ �ִµ� R�� �ռ��ִ� ��� -> R�� ���� ������
	if (temp == 1)
	{
		//	�������� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = R_bead[cnt].first; i < N; ++i)
		{
			if (map[i][R_col] == '.')
				continue;
			if (map[i][R_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][R_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			R_bead.push_back({ flag_hole, R_col });
			//	�Ķ����� �̵�
			B_bead.push_back({ flag_hole-1, B_col });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ flag_wall - 1, R_col });
			//	�Ķ����� �̵�
			B_bead.push_back({ flag_wall - 2, B_col });
		}
	}
	//	�������� ���� �࿡ �ִµ� B�� �ռ��ִ� ��� -> B�� ���� ������
	if (temp == 2)
	{
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].first; i < N; ++i)
		{
			if (map[i][B_col] == '.')
				continue;
			if (map[i][B_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][B_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ flag_hole, B_col });
			//	�������� �̵�
			R_bead.push_back({ flag_hole - 1, R_col });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ flag_wall - 1, B_col });
			//	�������� �̵�
			R_bead.push_back({ flag_wall - 2, R_col });
		}
	}
}

inline void go_north(int cnt)
{
	int temp = north_near_RB(cnt);
	int R_col = R_bead[cnt].second;
	int B_col = B_bead[cnt].second;
	int flag_hole = 0;
	int flag_wall = 0;
	//	�������� ���� ��/���� ���� ���� ���
	if (!temp)
	{
		//	�������� �̵�
		for (register int i = R_bead[cnt].first; i >= 0; --i)
		{
			if (map[i][R_col] == '.')
				continue;
			if (map[i][R_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][R_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		//���ۿ� ���� �����Ƿ�, �Ķ������� ������ �ʿ� ������ ����
		if (flag_hole)
		{
			R_bead.push_back({ flag_hole, R_col });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ flag_wall + 1, R_col });
		}
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].first; i >= 0; --i)
		{
			if (map[i][B_col] == '.')
				continue;
			if (map[i][B_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][B_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ flag_hole, B_col });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ flag_wall + 1 , B_col });
		}
	}
	//	�������� ���� �࿡ �ִµ� R�� �ռ��ִ� ��� -> R�� ���� ������
	if (temp == 1)
	{
		//	�������� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = R_bead[cnt].first; i >= 0; --i)
		{
			if (map[i][R_col] == '.')
				continue;
			if (map[i][R_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][R_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			R_bead.push_back({ flag_hole, R_col });
			//	�Ķ����� �̵�
			B_bead.push_back({ flag_hole + 1, B_col });
			return;
		}
		else if (flag_wall)
		{
			R_bead.push_back({ flag_wall + 1, R_col });
			//	�Ķ����� �̵�
			B_bead.push_back({ flag_wall + 2, B_col });
		}
	}
	//	�������� ���� �࿡ �ִµ� B�� �ռ��ִ� ��� -> B�� ���� ������
	if (temp == 2)
	{
		//	�Ķ����� �̵�
		flag_hole = 0;
		flag_wall = 0;
		for (register int i = B_bead[cnt].first; i >= 0; --i)
		{
			if (map[i][B_col] == '.')
				continue;
			if (map[i][B_col] == 'O')
			{
				flag_hole = i;
				break;
			}
			if (map[i][B_col] == '#')
			{
				flag_wall = i;
				break;
			}
		}
		if (flag_hole)
		{
			B_bead.push_back({ flag_hole, B_col });
			//	�������� �̵�
			R_bead.push_back({ flag_hole + 1, R_col });
			return;
		}
		else if (flag_wall)
		{
			B_bead.push_back({ flag_wall + 1, B_col });
			//	�������� �̵�
			R_bead.push_back({ flag_wall + 2, R_col });
		}
	}
}

inline void go(int cnt, int d)
{
	switch (d)
	{
	case 0:
		go_east(cnt);
		break;
	case 1:
		go_west(cnt);
		break;
	case 2:
		go_south(cnt);
		break;
	case 3:
		go_north(cnt);
		break;
	default:
		break;
	}
}
inline void dfs(int cnt)
{
	//	��������
	if (R_bead[cnt].first == hole.first && R_bead[cnt].second == hole.second)
	{
		result = min(result, cnt);
		return;
	}
	if (cnt > 10)
	{
		result = -1;
		return;
	}
	if (B_bead[cnt].first == hole.first && B_bead[cnt].second == hole.second)
	{
		result = -1;
		return;
	}
	if (cnt > 0)
	{
		if(R_bead[cnt].first == R_bead[cnt - 1].first && R_bead[cnt].second == R_bead[cnt - 1].second)
		{
			dfs(cnt);
		}
	}
	int check[DIRECT] = { 0, 0, 0, 0 };
	//	����κ�
	for (register int d = 0; d < DIRECT; ++d)
	{
		if (result == INF && !check[d])
		{
			check[d]++;
			go(cnt, d);
			dfs(cnt + 1);
			R_bead.pop_back();
			B_bead.pop_back();
			check[d] = 0;
		}
		else
			return;
	}
}

int main(int argc, char** argv)
{
	freopen("input13460.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> N >> M;
	init();
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 'O')
				hole = { r, c };
			else if (map[r][c] == 'R')
				R_bead.push_back({ r, c });
			else if (map[r][c] == 'B')
				B_bead.push_back({ r, c });
		}
	}
	dfs(0);
	cout << result;
	return 0;
}