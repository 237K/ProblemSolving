//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16236	�Ʊ���
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> coor;
typedef pair<int, coor> distance_and_coor;

const static int SIZE = 21;
const static int DIRECT = 4;
const static int INF = 2147000000;

static int map[SIZE][SIZE];
static bool check[SIZE][SIZE];
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static queue<distance_and_coor> Q_distance_and_coor;		//���� ���� �� �ִ� ���������� �Ÿ��� BFS�� ������ �� ����ϱ� ���� Q
static vector<distance_and_coor> vector_distance_sort;		//���� ���� �� �ִ� ������ �Ÿ��� ���Ϳ� �ְ� sort�� �� ù ��° ����⸦ ��ȯ
static queue<coor> Q_fish;									//�Է¹��� �� ������ ��ġ ����
static int N;

struct shark
{
	int x = 0, y = 0, size = 2, eat = 0;
	void move_and_swallow(int x, int y)
	{
		this->x = x;
		this->y = y;
		if (map[x][y] > 0 && map[x][y] < this->size)
		{
			if (++eat == size)
			{
				size++;
				eat = 0;
			}
			map[x][y] = 0;
		}
	}
};
static shark baby_shark;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, 0, sizeof(check));
	vector_distance_sort.clear();
	while (!Q_fish.empty()) { Q_fish.pop(); }
}

////////////���������� �Ÿ� ���� �Լ�/////////////////
inline int cal_distance(int fish_x, int fish_y)
{
	//int shortest_dist = INF;
	int shark_x = baby_shark.x;
	int shark_y = baby_shark.y;
	check[shark_x][shark_y] = true;
	Q_distance_and_coor.push({ 0, {shark_x, shark_y} });			//���� �Ʊ��� ��ġ��������
	while (!Q_distance_and_coor.empty())
	{
		distance_and_coor cur = Q_distance_and_coor.front();
		Q_distance_and_coor.pop();
		int curx = cur.second.first;
		int cury = cur.second.second;
		int curdist = cur.first;
		if (curx == fish_x && cury == fish_y)						//�Է¹��� ��ǥ�� �����ϸ�
		{
			while (!Q_distance_and_coor.empty()) { Q_distance_and_coor.pop(); }			//Q�� �����ؾ��ϹǷ� ����ְ�
			(void)memset(check, 0, sizeof(check));										//check�� �����ؾ��ϹǷ� �ʱ�ȭ�ϰ�
			//shortest_dist = min(shortest_dist, curdist);								
			return curdist;											//���� ���� ��ǥ������ ������ ��찡 ���� ª�� �Ÿ��̹Ƿ� ��ȯ
		}
		for (register int d = 0; d < DIRECT; ++d)					//���� ��ġ���� ������������ ���ƺ���
		{
			int nextx = curx + dir[d][0];
			int nexty = cury + dir[d][1];
			if (nextx < 0 || nexty < 0 || nextx >= N || nexty >= N || check[nextx][nexty] || map[nextx][nexty] > baby_shark.size)
				continue;
			else
			{
				check[nextx][nexty] = true;
				Q_distance_and_coor.push({ curdist + 1, {nextx, nexty} });		//�� �� �ִ� ���̸� �Ÿ�+1�ؼ� Q�� �������
			}
		}
	}
	return INF;
}

////////////���� �� �ִ� ����� �� ���� ������ �ִ� ����⸦ ã�� �Լ�////////////
inline distance_and_coor find_close_fish()
{
	int cycle = Q_fish.size();
	while (cycle--)									//���� ��������� �� �� ��ȸ��
	{												//���� �Ʊ���� ������ ũ�ų� �� �� ���� ���� �ִ� ������ �ٽ� Q�� push��
		coor cur_fish = Q_fish.front();
		Q_fish.pop();
		int x = cur_fish.first;
		int y = cur_fish.second;
		if (map[x][y] >= baby_shark.size)
		{
			Q_fish.push({ x, y });
			continue;
		}
		else
		{											//���� �� �ִ� ������̸�
			int distance = cal_distance(x, y);		//�Ÿ� ����غ���
			if (distance == INF || !distance)		//������
			{
				Q_fish.push({ x, y });				//�ٽ� Q�� ����ְ�
				continue;
			}
			else
			{
				vector_distance_sort.push_back({ distance, {x, y} });	//�� �� ������ ���Ϳ� �������
			}
		}
	}
	if (!vector_distance_sort.size())		//���Ͱ� �������(���� �� �ִ� ����Ⱑ ������)
		return { INF, {INF, INF} };

	sort(vector_distance_sort.begin(), vector_distance_sort.end());		//���� �� �ִ� �������� �Ÿ������� ������
																		//**�Ÿ��� 1����, �Ÿ��� ������ ���� �ִ°�(���� ������) �켱, �൵ ������ ������ �ִ°�(���� ������) �켱
	/*
	for (vector<distance_and_coor>::iterator iter = vector_distance_sort.begin(); iter != vector_distance_sort.end(); ++iter)
		cout << "(" << iter->second.first << ", " << iter->second.second << ") distance : " << iter->first << ' ';
	cout << "\n\n";
	*/

	distance_and_coor close_fish = vector_distance_sort[0];				//���� ����� �����
	int vector_size = vector_distance_sort.size();
	for (register int i = 1; i < vector_size; ++i)						//�̹��� ���� ����� ���� ������ �������� �ٽ� Q�� �������
	{
		Q_fish.push({ vector_distance_sort[i].second.first, vector_distance_sort[i].second.second });
	}
	vector_distance_sort.clear();
	return close_fish;						//�̹��� ���� ���� ����� ����� ��ȯ
}

////////////���� �Լ�////////////
inline int baby_shark_dululududu()
{
	int count = 0;
	while (!Q_fish.empty())											//���� �θ��� ������
	{
		distance_and_coor cur_target_fish = find_close_fish();		//�� �ѹ� �ѷ���
		int x = cur_target_fish.second.first;						//���� �� �ִ� ����� �� ���� ����� ����� ��ǥ
		int y = cur_target_fish.second.second;						
		int dist = cur_target_fish.first;							//���� �� �ִ� ����� �� ���� ����� ���������� �Ÿ�
		if (dist == INF || !dist)									//�� �̻� ���� �� �ִ� ����Ⱑ ������
			return count;											//��������� �ð� ��ȯ
		else
		{															
			baby_shark.move_and_swallow(x, y);						//���� ����
			count += dist;											//���µ� �Ÿ���ŭ �ð��� �ɸ�
		}
	}
	return count;
}

int main(int argc, char** argv)
{
	freopen("s_input16236.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	init();
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 9)
			{
				map[r][c] = 0;
				baby_shark.move_and_swallow(r, c);
			}
			else if (map[r][c] > 0 && map[r][c] <= 6)
			{
				Q_fish.push({ r, c });
			}
		}
	}
	cout << baby_shark_dululududu() <<'\n';
	return 0;
}