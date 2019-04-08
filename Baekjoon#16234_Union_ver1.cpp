//
//	OS Windows
//	2019.04.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16234	인구 이동
//
//	ver1. 시간초과

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> coor;
const static int SIZE = 51;
const static int MAX_NATION = SIZE * SIZE;
const static int DIRECT = 4;

struct Nation
{
	coor location;
	int nation_id, population, union_id;
};

static int map[SIZE][SIZE];
static Nation nations[MAX_NATION];
static queue<Nation> Q_nation;
static vector<int> vector_union[MAX_NATION/2];
static int N, L, R;
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

inline void init_union()
{
	for (int n = 0; n < N*N; ++n)
	{
		nations[n].union_id = 0;
	}
	for (int i = 0; i < MAX_NATION / 2; ++i)
	{
		vector_union[i].clear();
	}
}

inline int find_nation(int r, int c)
{
	for (int n = 0; n < N*N; ++n)
	{
		if (nations[n].location.first == r && nations[n].location.second == c)
		{
			return n;
		}
	}
	return -1;
}

inline bool find_union(int ui)
{
	bool flag = false;
	while (!Q_nation.empty())
	{
		Nation cur = Q_nation.front();
		Q_nation.pop();
		int cur_r = cur.location.first;
		int cur_c = cur.location.second;
		for (int d = 0; d < DIRECT; ++d)
		{
			int nr = cur_r + dir[d][0];
			int nc = cur_c + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			int next_nation = find_nation(nr, nc);
			if (nations[next_nation].union_id)
				continue;
			if (abs(nations[next_nation].population - cur.population) >= L && abs(nations[next_nation].population - cur.population) <= R)
			{
				nations[next_nation].union_id = ui;
				vector_union[ui].push_back(next_nation);
				Q_nation.push(nations[next_nation]);
				flag = true;
			}
		}
	}
	return flag;
}



inline int open()
{
	int count = 0;
	while (1)
	{
		//cout << "count : " << count << '\n';
		//print_map();
		//합병 가능한 국가들을 찾아서 vector_union[union_idx]에 넣음
		int union_idx = 1;
		for (int n = 0; n < N*N; ++n)
		{
			if (!nations[n].union_id)
			{
				nations[n].union_id = union_idx;
				vector_union[union_idx].push_back(n);
				Q_nation.push(nations[n]);
				if (find_union(union_idx))
					union_idx++;
				else
				{
					nations[n].union_id = 0;
					vector_union[union_idx].pop_back();
				}
			}
		}
		//연합을 구성할 국가가 없으면 끝
		if (union_idx < 2)
			break;
		//연합이 존재하면
		else
		{
			//각 연합을 돌면서 인구이동
			for (int ui = 1; ui <= union_idx ; ++ui)
			{
				int union_nations_num = vector_union[ui].size();
				if (!union_nations_num)
					continue;
				else
				{
					int union_total_population = 0;
					int union_nations_population = 0;
					for (int s = 0; s < union_nations_num; ++s)
					{
						int cur_nation_id = vector_union[ui][s];
						union_total_population += nations[cur_nation_id].population;
					}
					union_nations_population = union_total_population / union_nations_num;
					for (int s = 0; s < union_nations_num; ++s)
					{
						int cur_nation_id = vector_union[ui][s];
						nations[cur_nation_id].population = union_nations_population;
						map[nations[cur_nation_id].location.first][nations[cur_nation_id].location.second] = union_nations_population;
					}
				}
			}
			count++;
		}
		init_union();
	}
	return count;
}

int main(int argc, char** argv)
{
	freopen("s_input16234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	int idx = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			nations[idx++] = { {r, c}, idx, map[r][c], 0 };
		}
	}
	cout << open();
	return 0;
}