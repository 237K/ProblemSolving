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
		//	���� ��ġ û��
		if (!map[cr][cc])
		{
			result++;
			map[cr][cc] = -1;
		}
		//print(cr, cc);
		//	���� ��ġ�� �������� �������� 90���� ȸ���ϸ鼭 4���� �˻�
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nd = (cd + 3) % 4;
			int nr = cr + dir[nd][0];
			int nc = cc + dir[nd][1];
			//	������ �˻�
			if (map[nr][nc] == 1)
			{
				back_flag++;
				cd = nd;
				continue;
			}
			//	���� �ƴϸ� �� ���⿡ û���� ���� �ִ��� �˻�
			if (search(cr, cc, nd))
			{
				//	�̵��� �� �ְ� û���� ���� ������ �� �������� ȸ���ϰ� �̵�
				back_flag = 0;
				cr = nr;
				cc = nc;
				cd = nd;
				break;
			}
			//	���� �ƴѵ� û���� ���� ������
			else
			{
				cd = nd;
				back_flag++;
				continue;
			}
		}
		//	4���� �� ���̰ų� û���� ���� ������
		if (back_flag == 4)
		{
			int bnd = (cd + 2) % 4;
			int bnr = cr + dir[bnd][0];
			int bnc = cc + dir[bnd][1];
			//	������ �� �ִ��� �˻��ϰ�, ���ʵ� ���̸� ����
			if (map[bnr][bnc] == 1)
				break;
			//	������ ���� �ƴϸ� ������ �ٲ��� �ʰ� �� ĭ ����
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