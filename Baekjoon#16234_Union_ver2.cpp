//
//	OS Windows
//	2019.04.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16234	인구 이동
//
//	ver1. 시간초과
//	ver2. PASS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> coor;
const static int SIZE = 51;
const static int MAX_NATION = SIZE * SIZE;
const static int DIRECT = 4;
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static int nations[SIZE][SIZE];
static int union_id[SIZE][SIZE];
static int union_total_population[MAX_NATION];
static int union_nation_number[MAX_NATION];
static int N, L, R;
static queue<coor> Q;

inline void init()
{
	(void)memset(union_id, 0, sizeof(union_id));
	(void)memset(union_total_population, 0, sizeof(union_total_population));
	(void)memset(union_nation_number, 0, sizeof(union_nation_number));
}
inline void print_nations()
{
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cout << nations[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << '\n';
}
inline bool find_union(int ui)
{
	bool flag = false;
	while (!Q.empty())
	{
		coor cur = Q.front();
		Q.pop();
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nr = cur.first + dir[d][0];
			int nc = cur.second + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || union_id[nr][nc])
				continue;
			if (abs(nations[cur.first][cur.second] - nations[nr][nc]) >= L && abs(nations[cur.first][cur.second] - nations[nr][nc]) <= R)
			{
				union_id[nr][nc] = ui;
				union_total_population[ui] += nations[nr][nc];
				union_nation_number[ui]++;
				Q.push({ nr, nc });
				flag = true;
			}
		}
	}
	return flag;
}

inline int set_union()
{
	int count = 0;
	while (1)
	{
		//print_nations();
		bool flag = false;
		//합병할 수 있는 국가들을 클러스터링하고
		int num_of_union = 1;
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				if (!union_id[r][c])
				{
					union_id[r][c] = num_of_union;
					union_total_population[num_of_union] += nations[r][c];
					union_nation_number[num_of_union]++;
					Q.push({ r, c });
					if (find_union(num_of_union))
						flag = true;
					num_of_union++;
				}
			}
		}
		//연합할 국가가 없으면 종료
		if (!flag)
			return count;
		//인구 이동
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				int ui = union_id[r][c];
				if (union_nation_number[ui] == 1)
					continue;
				else if (union_nation_number[ui] > 1)
				{
					int union_average_population = union_total_population[ui] / union_nation_number[ui];
					nations[r][c] = union_average_population;
				}
			}
		}
		count++;
		init();
	}
}

int main(int argc, char** argv)
{
	freopen("s_input16234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cin >> nations[r][c];
		}
	}
	cout << set_union();
	return 0;
}