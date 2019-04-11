//
//	OS Windows
//	2019.04.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #12100	2048
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
const static int SIZE = 20;
const static int DIRECT = 4;
const static int INF = -2147000000;

static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SIZE][SIZE];
static int map_cpy[SIZE][SIZE];
static int check[SIZE][SIZE];
static int N;
static vector<int> result;

inline void print_vector(vector<int> v)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << '\n';
}
inline void print_map()
{
	cout << "==============================\n";
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "==============================\n\n";
}
inline void push_and_sort()
{
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			if (map[r][c])
				result.push_back(map[r][c]);
		}
	}
}
inline bool valid(int cnt, int d, vector<int> v)
{
	if (!cnt)
		return true;
	else
	{
		if (v[cnt - 1] == d || v[cnt - 1] == (d + 2) % 4)
		{
			return false;
		}
	}
	return true;
}
inline void move_or_add(int d, int r, int c)
{
	int nr = r + dir[d][0];
	int nc = c + dir[d][1];
	int cur_number = map[r][c];
	if (nr < 0 || nc < 0 || nr >= N || nc >= N || !cur_number)
		return;
	else
	{
		if (cur_number && cur_number == map[nr][nc] && !check[nr][nc])
		{
			map[nr][nc] *= 2;
			check[nr][nc] = 1;
			map[r][c] = 0;
		}
		if (!map[nr][nc])
		{
			swap(map[r][c], map[nr][nc]);
			move_or_add(d, nr, nc);
		}
	}
}
inline void move(vector<int> v)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		(void)memset(check, 0, sizeof(check));
		int cur_dir = *iter;
		switch (cur_dir)
		{
		case 0:
			for (register int r = 0; r < N; ++r)
			{
				for (register int c = N - 2; c >= 0; --c)
				{
					move_or_add(cur_dir, r, c);
				}
			}
			break;
		case 1:
			for (register int c = 0; c < N; ++c)
			{
				for (register int r = N - 2; r >= 0; --r)
				{
					move_or_add(cur_dir, r, c);
				}
			}
			break;
		case 2:
			for (register int r = 0; r < N; ++r)
			{
				for (register int c = 1; c < N; ++c)
				{
					move_or_add(cur_dir, r, c);
				}
			}
			break;
		case 3:
			for (register int c = 0; c < N; ++c)
			{
				for (register int r = 1; r < N; ++r)
				{
					move_or_add(cur_dir, r, c);
				}
			}
			break;
		default:
			break;
		}

	}
}
inline void recur(int count, vector<int>& v)
{
	if (count > 5)
	{
		//print_vector(v);
		move(v);
		//print_map();
		push_and_sort();
		(void)memcpy(map, map_cpy, sizeof(map));
		(void)memset(check, 0, sizeof(check));
		return;
	}
	else
	{
		for(register int d = 0 ; d < DIRECT ; ++d)
		{
			//if (!valid(count, d, v))
				//continue;
			//else
			//{
				v.push_back(d);
				recur(count + 1, v);
				v.pop_back();
			//}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input12100.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	(void)memset(map, 0, sizeof(map));
	(void)memset(check, 0, sizeof(check));
	result.clear();
	cin >> N;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			map_cpy[r][c] = map[r][c];
		}
	}
	vector<int> order;
	recur(0, order);
	sort(result.begin(), result.end(), greater<int>());
	cout << result[0];
	return 0;
}