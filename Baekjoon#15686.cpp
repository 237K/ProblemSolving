//
//	OS Windows
//	2019.04.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15686	치킨 배달
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> coor;
const static int SIZE = 51;
const static int MAX = 14;
const static int MAX_HOUSE = 102;
static int map[SIZE][SIZE];
static int N, M;
static vector<coor> house;
static vector<coor> chiken;
static vector<int> selected_chiken;
static int check[MAX];
static int result;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, 0, sizeof(check));
	chiken.clear();
	house.clear();
	selected_chiken.clear();
	result = 214700000;
}
inline void print(vector<int> v)
{
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << "\n\n";
}
inline void recur(int count, int idx)
{
	if (count == M)
	{
		//print(selected_chiken);
		int temp_total_dist = 0;
		for (vector<int>::size_type h = 0; h < house.size(); ++h)
		{
			int dist = 999;
			for (register int c = 0; c < M; ++c)
			{
				int temp_dist = 0;
				int cur_chiken_idx = selected_chiken[c];
				temp_dist = abs(house[h].first - chiken[cur_chiken_idx].first) + abs(house[h].second - chiken[cur_chiken_idx].second);
				dist = min(dist, temp_dist);
			}
			temp_total_dist += dist;
		}
		result = min(result, temp_total_dist);
		return;
	}
	else
	{
		int num_of_chiken = chiken.size();
		for (register int i = idx; i < num_of_chiken; ++i)
		{
			if (!check[i])
			{
				check[i] = 1;
				selected_chiken.push_back(i);
				recur(count + 1, i + 1);
				check[i] = 0;
				selected_chiken.pop_back();
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input2.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	init();
	cin >> N >> M;
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 1)
			{
				house.push_back({ r, c });
			}
			if (map[r][c] == 2)
			{
				chiken.push_back({ r, c });
			}
		}
	}
	recur(0, 0);
	cout << result;
	return 0;
}