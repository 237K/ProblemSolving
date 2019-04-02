//
//	OS Windows
//	2019.04.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5653] <�ٱ⼼�����> (���� SW �����׽�Ʈ)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

const static int MAP_SIZE = 310;
const static int DIRECT = 4;

static int N, M, K;
static int map[MAP_SIZE * 2 + 51][MAP_SIZE * 2 + 51];
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

struct cell									//������ ��ǥ�� ������� ������ �ִ� ����ü
{
	int x, y, life;
	bool operator<(const cell& c) const		//�켱����ť���� �켱���� �񱳸� ���� ������ �����ε�
	{
		return life < c.life;
	}
};
static priority_queue<cell> PQ;
static queue<cell> Q;

inline int tiktok()							
{
	int sleep = 0;							//��Ȱ��ȭ�� ������
	int wakeup = 0;							//Ȱ��ȭ�� ������

	while (!PQ.empty())
	{
		Q.push(PQ.top());
		PQ.pop();
	}
	while (K--)								//1�ð� ����
	{
		int tik = Q.size();					//���� Q�� ��� �������� Ȱ����
		while (tik--)
		{
			cell cur_cell = Q.front();
			Q.pop();

			if (cur_cell.life-- == 0)		//������ Ȱ��ȭ�� ���� �Ǹ�
			{
				if (map[cur_cell.x][cur_cell.y] - 1 > K)	//�ð��� �� ���������� Ȱ��ȭ�� �ȵ� ����++
					sleep++;
				for (register int d = 0; d < DIRECT; ++d)	//4�������� ���캸��
				{
					int x = cur_cell.x + dir[d][0];
					int y = cur_cell.y + dir[d][1];

					if (map[x][y])
						continue;
					else if (!map[x][y])					//���������
					{
						map[x][y] = map[cur_cell.x][cur_cell.y];	//����
						Q.push({ x, y, map[x][y] });
					}
				}
			}
			else
				Q.push({ cur_cell.x, cur_cell.y, cur_cell.life });
		}
	}
	wakeup = Q.size();
	return sleep + wakeup;
}

int main(int argc, char** argv)
{
	freopen("s_input5653.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		while (!PQ.empty()) { PQ.pop(); }
		while (!Q.empty()) { Q.pop(); }
		cin >> N >> M >> K;
		for (register int r = MAP_SIZE; r < MAP_SIZE + N; ++r)
		{
			for (register int c = MAP_SIZE; c < MAP_SIZE + M; ++c)
			{
				cin >> map[r][c];
				if (map[r][c])
					PQ.push({ r, c, map[r][c] });
			}
		}
		cout << "#" << test_case << ' ' << tiktok() << '\n';
	}
	return 0;
}