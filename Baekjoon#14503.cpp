//
//	OS Windows
//	2019.04.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14503	�κ� û�ұ�
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
	//	���� ������ �����̸� ���� Ž��
	if (cur_d == 0)
	{
		for (register int c = cur_c; c >= 0; --c)
		{
			if (!map[cur_r][c] && !check[cur_r][c])
				return true;
		}
	}
	//	���� ������ �����̸� ���� Ž��
	else if (cur_d == 1)
	{
		for (register int r = cur_r; r >= 0; --r)
		{
			if (!map[r][cur_c] && !check[r][cur_c])
				return true;
		}
	}
	//	���� ������ �����̸� ���� Ž��
	else if (cur_d == 2)
	{
		for (register int c = cur_c; c < M; ++c)
		{
			if (!map[cur_r][c] && !check[cur_r][c])
				return true;
		}
	}
	//	���� ������ �����̸� ���� Ž��
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
	//	������ġ�� û���ϰ� ����
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

		//	���ʿ� û���� ���� �ֵ� ���� �κ�û�ұ� ������ �������� ȸ����
		int nd = (cd + 3) % 4;

		//	���ʿ� û���� ���� �ִ��� Ž���غ���
		//	û���� ���� ������ �������� ȸ���ϰ� �� ĭ ������.
		if (search_left(cr, cc, cd))
		{
			int nr = cr + dir[nd][0];
			int nc = cc + dir[nd][1];
			//	���� ���� ������ ������ ������ä�� �� ĭ ������
			if (map[nr][nc])
			{
				int back_dir = (nd + 2) % 4;
				int nnr = nr + dir[back_dir][0];
				int nnc = nc + dir[back_dir][1];
				//	������ ���ϸ� ���ڸ����� �������� �� ȸ��
				if (map[nnr][nnc])
				{
					int nnd = (nd + 3) % 4;
					Q.push({ {cr, cc}, nnd });
					end_flag++;
					continue;
				}
				//	���� **�������� ��� û�Ҵ� ����!
				else if (!map[nnr][nnc])
				{
					Q.push({ {nnr, nnc}, nd });
					end_flag = 0;
					continue;
				}
			}
			//	�� ĭ �����ϰ�, ���� û�Ҿ������� û���ϰ� üũ��
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
		//	û���� ���� ������ ���ڸ����� ȸ���� ��
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