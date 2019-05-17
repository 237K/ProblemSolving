//
//	OS Windows
//	2019.05.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5653] <줄기세포배양> (모의)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

struct CELL
{
	int r, c, life, time;
	bool operator< (const CELL& c) const
	{
		return c.life < life;
	}
};

const static int DIRECT = 4;
const static int SIZE = 700;
static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static vector<CELL> cell;
static vector<CELL> spread_cell;
static int map[SIZE][SIZE];
static int N, M, K;

inline void spread(int n)
{
	//	같은 곳에 번식할 때 life가 큰 세포가 번식하기 위해 life기준으로 내림차순 정렬
	sort(spread_cell.begin(), spread_cell.end());
	for (register int i = 0; i < n; ++i)
	{
		CELL cur_cell = spread_cell[i];
		int cr = cur_cell.r;
		int cc = cur_cell.c;
		for (register int d = 0; d < DIRECT; ++d)
		{
			int nr = cr + dir[d][0];
			int nc = cc + dir[d][1];
			if (!map[nr][nc])
			{
				map[nr][nc] = cur_cell.life;
				cell.push_back({ nr, nc, cur_cell.life, 0 });
			}
		}
	}
}
inline int simulation()
{
	int result = 0;
	while (1)
	{
		K--;
		int cnt = 0;
		int spread_flag = 0;
		spread_cell.clear();
		int num = cell.size();
		for (register int n = 0; n < num; ++n)
		{
			if (cell[n].life)
			{
				cnt++;
				if (cell[n].time == cell[n].life)
				{
					spread_flag++;
					spread_cell.push_back(cell[n]);
				}
				else if (cell[n].time == cell[n].life * 2)
				{
					cnt--;
					cell[n].life = 0;
				}
				cell[n].time++;
			}
		}

		//	번식할 세포 있으면 번식
		if (spread_flag) spread(spread_flag);
		result = cnt;

		if (K < 0) break;
	}
	return result;
}
int main(void)
{
	freopen("s_input5653.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, r, c;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		cell.clear();
		cin >> N >> M >> K;
		for (r = 300; r < N + 300; ++r)
		{
			for (c = 300; c < M + 300; ++c)
			{
				cin >> map[r][c];
				if (map[r][c]) cell.push_back({ r, c, map[r][c], 0 });
			}
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}