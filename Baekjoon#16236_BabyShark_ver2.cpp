//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16236	아기상어
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
static queue<distance_and_coor> Q_distance_and_coor;		//현재 먹을 수 있는 물고기까지의 거리를 BFS로 측정할 때 사용하기 위한 Q
static vector<distance_and_coor> vector_distance_sort;		//현재 먹을 수 있는 물고기와 거리를 벡터에 넣고 sort한 후 첫 번째 물고기를 반환
static queue<coor> Q_fish;									//입력받을 때 물고기들 위치 저장
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

////////////물고기까지의 거리 측정 함수/////////////////
inline int cal_distance(int fish_x, int fish_y)
{
	//int shortest_dist = INF;
	int shark_x = baby_shark.x;
	int shark_y = baby_shark.y;
	check[shark_x][shark_y] = true;
	Q_distance_and_coor.push({ 0, {shark_x, shark_y} });			//현재 아기상어 위치에서부터
	while (!Q_distance_and_coor.empty())
	{
		distance_and_coor cur = Q_distance_and_coor.front();
		Q_distance_and_coor.pop();
		int curx = cur.second.first;
		int cury = cur.second.second;
		int curdist = cur.first;
		if (curx == fish_x && cury == fish_y)						//입력받은 좌표에 도달하면
		{
			while (!Q_distance_and_coor.empty()) { Q_distance_and_coor.pop(); }			//Q는 재사용해야하므로 비워주고
			(void)memset(check, 0, sizeof(check));										//check도 재사용해야하므로 초기화하고
			//shortest_dist = min(shortest_dist, curdist);								
			return curdist;											//제일 먼저 목표지점에 도달한 경우가 제일 짧은 거리이므로 반환
		}
		for (register int d = 0; d < DIRECT; ++d)					//현재 위치에서 동서남북으로 돌아보고
		{
			int nextx = curx + dir[d][0];
			int nexty = cury + dir[d][1];
			if (nextx < 0 || nexty < 0 || nextx >= N || nexty >= N || check[nextx][nexty] || map[nextx][nexty] > baby_shark.size)
				continue;
			else
			{
				check[nextx][nexty] = true;
				Q_distance_and_coor.push({ curdist + 1, {nextx, nexty} });		//갈 수 있는 곳이면 거리+1해서 Q에 집어넣음
			}
		}
	}
	return INF;
}

////////////먹을 수 있는 물고기 중 가장 가까이 있는 물고기를 찾는 함수////////////
inline distance_and_coor find_close_fish()
{
	int cycle = Q_fish.size();
	while (cycle--)									//현재 물고기목록을 한 번 순회함
	{												//현재 아기상어보다 몸집이 크거나 갈 수 없는 곳에 있는 물고기는 다시 Q에 push함
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
		{											//먹을 수 있는 물고기이면
			int distance = cal_distance(x, y);		//거리 계산해보고
			if (distance == INF || !distance)		//못가면
			{
				Q_fish.push({ x, y });				//다시 Q에 집어넣고
				continue;
			}
			else
			{
				vector_distance_sort.push_back({ distance, {x, y} });	//갈 수 있으면 벡터에 집어넣음
			}
		}
	}
	if (!vector_distance_sort.size())		//벡터가 비었으면(먹을 수 있는 물고기가 없으면)
		return { INF, {INF, INF} };

	sort(vector_distance_sort.begin(), vector_distance_sort.end());		//먹을 수 있는 물고기들을 거리순으로 정렬함
																		//**거리가 1순위, 거리가 같으면 높이 있는게(행이 작은게) 우선, 행도 같으면 좌측에 있는게(열이 작은게) 우선
	/*
	for (vector<distance_and_coor>::iterator iter = vector_distance_sort.begin(); iter != vector_distance_sort.end(); ++iter)
		cout << "(" << iter->second.first << ", " << iter->second.second << ") distance : " << iter->first << ' ';
	cout << "\n\n";
	*/

	distance_and_coor close_fish = vector_distance_sort[0];				//제일 가까운 물고기
	int vector_size = vector_distance_sort.size();
	for (register int i = 1; i < vector_size; ++i)						//이번에 먹을 물고기 말고 나머지 물고기들은 다시 Q에 집어넣음
	{
		Q_fish.push({ vector_distance_sort[i].second.first, vector_distance_sort[i].second.second });
	}
	vector_distance_sort.clear();
	return close_fish;						//이번에 먹을 제일 가까운 물고기 반환
}

////////////실행 함수////////////
inline int baby_shark_dululududu()
{
	int count = 0;
	while (!Q_fish.empty())											//엄마 부르기 전까지
	{
		distance_and_coor cur_target_fish = find_close_fish();		//슥 한번 둘러봄
		int x = cur_target_fish.second.first;						//먹을 수 있는 물고기 중 제일 가까운 물고기 좌표
		int y = cur_target_fish.second.second;						
		int dist = cur_target_fish.first;							//먹을 수 있는 물고기 중 제일 가까운 물고기까지의 거리
		if (dist == INF || !dist)									//더 이상 먹을 수 있는 물고기가 없으면
			return count;											//현재까지의 시간 반환
		else
		{															
			baby_shark.move_and_swallow(x, y);						//가서 먹음
			count += dist;											//가는데 거리만큼 시간이 걸림
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