//
//	OS Windows
//	2019.05.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17142	연구소3
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> coor;
const static int SZ = 50;
const static int VIRUS = 10;
const static int DIRECT = 4;
static int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int N, M, n_virus, n_empty;
static int map[SZ][SZ];
static int map_cpy[SZ][SZ];
static coor virus[VIRUS];
static queue<coor> Q;

inline int simulation()
{
	if (!n_empty) return 0;

	int ret = 2147000000, tik = 0, end_flag = 0;
	register int mask, flag, cnt, d, nr, nc, n_spread;
	//	어느 자리에 놓을 지 선택
	for (mask = 0; mask < (1 << n_virus); ++mask)
	{
		(void)memcpy(map, map_cpy, sizeof(map));
		cnt = 0; tik = 0; n_spread = 0; end_flag = 0;
		while (!Q.empty()) { Q.pop(); }

		//	모든 바이러스 중에 M개를 선택했는지 확인
		for (flag = 0; flag < n_virus; ++flag)
		{
			if (mask & (1 << flag)) cnt++;
		}
		if (cnt != M) continue;

		//	M개를 선택했으면 큐에 넣고
		else if (cnt == M)
		{
			for (flag = 0; flag < n_virus; ++flag)
			{
				if (mask & (1 << flag))
				{
					Q.push(virus[flag]);
					map[virus[flag].first][virus[flag].second] = 3;
				}
			}
			//	복제 (복제되는데 1초 소요)
			while (!Q.empty())
			{
				if (end_flag)
					break;
				if ((tik++) > ret)
					break;
				int tik_tok = Q.size();
				while (tik_tok--)
				{
					coor cur_virus = Q.front();
					Q.pop();
					for (d = 0; d < DIRECT; ++d)
					{
						nr = cur_virus.first + dir[d][0];
						nc = cur_virus.second + dir[d][1];
						if (nr < 0 || nc < 0 || nr > N - 1 || nc > N - 1 || map[nr][nc] == 1 || map[nr][nc] == 3)
							continue;
						if (!map[nr][nc])
						{
							n_spread++;
							map[nr][nc] = 3;
							Q.push({ nr, nc });
						}
						if (map[nr][nc] == 2)
						{
							map[nr][nc] = 3;
							Q.push({ nr, nc });
						}
					}
				}
				if (n_spread == n_empty)
				{
					end_flag = 1;
				}
			}
			if (end_flag && ret > tik) ret = tik;
		}
	}
	if (ret == 2147000000)
		ret = -1;
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input17142.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	n_virus = 0; n_empty = 0;

	register int r, c;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (!map[r][c]) n_empty++;
			else if (map[r][c] == 2)
			{
				virus[n_virus++] = { r, c };
			}
			map_cpy[r][c] = map[r][c];
		}
	}
	cout << simulation();
	return 0;
}