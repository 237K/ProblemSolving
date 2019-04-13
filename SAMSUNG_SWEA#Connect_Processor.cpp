//
//	OS Windows
//	2019.04.13
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <프로세서 연결하기>
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> core_and_dir;

const static int SIZE = 12;
const static int MAX_CELL = 444;
const static int DIRECT = 4;
const static int INF = 2147000000;

static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int map[SIZE][SIZE];
static int map_cpy[SIZE][SIZE];
static vector<int> core_list;
static int core_state[MAX_CELL];
static int core_possible_dir[MAX_CELL][DIRECT];
static int core_check[MAX_CELL];
static int dir_check[MAX_CELL][DIRECT];
static int N;
static int result;
static int num_of_core;
static vector<core_and_dir> selected;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(map_cpy, 0, sizeof(map_cpy));
	(void)memset(core_state, 0, sizeof(core_state));
	(void)memset(core_possible_dir, 0, sizeof(core_possible_dir));
	(void)memset(core_check, 0, sizeof(core_check));
	(void)memset(dir_check, 0, sizeof(dir_check));
	result = INF;
	num_of_core = 0;
	selected.clear();
	core_list.clear();
}
inline void print(vector<core_and_dir> v)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << "core " << iter->first << " dir " << iter->second << '\n';
	cout << '\n';
}
inline void research()
{
	for (vector<int>::iterator iter = core_list.begin(); iter != core_list.end(); ++iter)
	{
		int cur_core_row = *iter / N;
		int cur_core_col = *iter % N;

		//	위쪽 검사
		bool flag = true;
		int len = 0;
		for (register int r = cur_core_row - 1; r >= 0; --r)
		{
			if (map[r][cur_core_col])
				flag = false;
			else
				len++;
		}
		if (flag)
			core_possible_dir[*iter][0] = len;

		//	오른쪽 검사
		flag = true;
		len = 0;
		for (register int c = cur_core_col + 1; c < N; ++c)
		{
			if (map[cur_core_row][c])
				flag = false;
			else
				len++;
		}
		if (flag)
			core_possible_dir[*iter][1] = len;

		//	아래쪽 검사
		flag = true;
		len = 0;
		for (register int r = cur_core_row + 1; r < N; ++r)
		{
			if (map[r][cur_core_col])
				flag = false;
			else
				len++;
		}
		if (flag)
			core_possible_dir[*iter][2] = len;

		//	왼쪽 검사
		flag = true;
		len = 0;
		for (register int c = cur_core_col - 1; c >= 0; --c)
		{
			if (map[cur_core_row][c])
				flag = false;
			else
				len++;
		}
		if (flag)
			core_possible_dir[*iter][3] = len;
	}
}
inline int test(int num)
{
	int wire = 0;
	for (register int c = 0; c < num; ++c)
	{
		int cur_idx = selected[c].first;
		int cur_dir = selected[c].second;
		int cr = cur_idx / N;
		int cc = cur_idx % N;
		while (1)
		{
			int nr = cr + dir[cur_dir][0];
			int nc = cc + dir[cur_dir][1];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				break;

			if (map[nr][nc])
				return 0;

			wire++;
			map[nr][nc] = cur_idx;
			cr = nr;
			cc = nc;
		}
	}
	return wire;
}
inline void recur(int num_connect, int count, int idx)
{
	if (count == num_connect)
	{
		int length = test(num_connect);
		if (length)
		{
			result = min(result, length);
			/*
			if (length < 26)
			{
				cout << "======================================================\n";
				cout << "코어 " << num_connect << " 개\n";
				cout << "--------------------------------------------------------\n";
				print(selected);
				cout << "전선길이 " << length << '\n';
				cout << "======================================================\n\n";
			}
			*/
		}
		(void)memcpy(map, map_cpy, sizeof(map));
		return;
	}
	else
	{
		for (register int c = idx; c < num_of_core; ++c)
		{
			for (register int d = 0; d < DIRECT; ++d)
			{
				if (!core_check[core_list[c]] && !dir_check[core_list[c]][d] && core_possible_dir[core_list[c]][d])
				{
					core_check[core_list[c]] = 1;
					dir_check[core_list[c]][d] = 1;
					selected.push_back({ core_list[c], d });
					recur(num_connect, count + 1, c + 1);
					selected.pop_back();
					core_check[core_list[c]] = 0;
					dir_check[core_list[c]][d] = 0;
				}
			}
		}
	}
}
inline void simulation()
{
	//	각 코어에서 가능한 모든 경우의 수를 저장
	research();
	//	모든 코어에 연결하는 경우부터 하나씩 연결 못하는 경우로 내려가면서 전선길이 합의 최소값을 구함
	for (register int i = num_of_core; i > 0; --i)
	{
		recur(i, 0, 0);
		if (result == INF)
			continue;
		else
			return;
	}
}
int main(int argc, char** argv)
{
	freopen("s_inputAP.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
				map_cpy[r][c] = map[r][c];
				if (r != 0 && r != N-1 && c != 0 && c != N-1 && map[r][c])
				{
					core_list.push_back(r*N + c);
					num_of_core++;
				}
			}
		}
		simulation();
		cout << "#" << test_case << ' ' << result << '\n';
	}
	return 0;
}