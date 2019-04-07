//
//	OS Windows
//	2019.04.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2382> �̻��� �ݸ� (����)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const static int SIZE = 101;
const static int DIRECT = 5;

struct CELL
{
	int id, row, col, number, direct, alive;
	bool operator< (const CELL& c) const
	{
		return c.number < number;
	}
};

static int dir[DIRECT][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
static int N, M, K;
static vector<CELL> cell;
static vector<CELL> map[SIZE][SIZE];

inline void init_map()
{
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			map[r][c].clear();
		}
	}
}
inline void crush(CELL& c, int row, int col)
{
	c.row = row;
	c.col = col;
	c.number = c.number / 2;
	if (!c.number)
		c.alive = 0;
	switch (c.direct)
	{
	case 1:
	case 3:
		c.direct += 1;
		break;
	case 2:
	case 4:
		c.direct -= 1;
		break;
	default:
		break;
	}
}
inline void move(CELL& c, int row, int col)
{
	c.row = row;
	c.col = col;
}
inline int count()
{
	int result = 0;
	for (vector<CELL>::size_type i = 0; i < cell.size(); ++i)
	{
		if (!cell[i].alive)
			continue;
		else
		{
			result += cell[i].number;
		}
	}
	return result;
}
inline int simulation()
{
	while (M--)
	{
		//�������� ������ �������� �� ĭ�� �̵�
		for (register int i = 0; i < K; ++i)
		{
			if (!cell[i].alive)
				continue;
			//������ ����ִٸ�
			else
			{
				//�̵��������� �� ĭ �̵��ϴµ�,
				int r = cell[i].row + dir[cell[i].direct][0];
				int c = cell[i].col + dir[cell[i].direct][1];
				//�ܰ� ���� �ε����� ���ڰ� �������� �ٰ�, �̵������� �ݴ�� �ٲ�
				if (!r || !c || r == N - 1 || c == N - 1)
					crush(cell[i], r, c);
				//�ƴϸ� �׳� �� ĭ ������
				else
					move(cell[i], r, c);
				//���� ��ǥ�� ���� ������ �ִ� ��� ��ġ�� ���� üũ�ص�
				map[r][c].push_back(cell[i]);
			}
		}
		//���� ��ǥ�� �ִ� �������� �ִ��� Ȯ���ϰ�
		for (register int r = 1; r < N - 1; ++r)
		{
			for (register int c = 1; c < N - 1; ++c)
			{
				//�� ��ǥ�� ������ �ϳ��� �ְų� �ϳ��� ������ �׳� �Ѿ��
				if (map[r][c].size() <= 1)
					continue;
				//�׷��� ������
				else
				{
					//���� �� �̻��� ���� ����(������ �켱)���� ������ ����
					sort(map[r][c].begin(), map[r][c].end());
					int bigger_cell_id = map[r][c][0].id;
					//���� ū �������� �� ��ġ�� �������� ����
					for (vector<CELL>::size_type i = 1; i < map[r][c].size(); ++i)
					{
						int die_cell_id = map[r][c][i].id;
						cell[bigger_cell_id].number += cell[die_cell_id].number;
						cell[die_cell_id].number = 0;
						cell[die_cell_id].alive = 0;
					}
				}
			}
		}
		init_map();
	}
	return count();
}
int main(int argc, char** argv)
{
	freopen("s_input2382.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		init_map();
		cell.clear();
		int r = 0, c = 0, init_num = 0, init_dir = 0;
		for (register int k = 0; k < K; ++k)
		{
			cin >> r >> c >> init_num >> init_dir;
			cell.push_back({ k, r, c, init_num, init_dir, 1 });
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}