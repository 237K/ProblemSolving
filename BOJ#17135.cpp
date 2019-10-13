//
//	OS Windows
//	2019.10.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17135 Ä³½½ µðÆæ½º
//

#include <iostream>
#include <memory.h>
using namespace std;
const int ARCHER = 3;
const int SZ = 16;
static int archer[ARCHER], check[ARCHER], target_dist[ARCHER], target_r[ARCHER], target_c[ARCHER];
static int map[SZ][SZ], map_cpy[SZ][SZ];
static int N, M, D, ret;
inline void print()
{
	cout << "============================================\n\n";
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "============================================\n\n";
}
inline int simul()
{
	register int init, t, r, c, d, dr, dc, a, ar, ac, flag, cnt = 0;
	for (t = N; t > 0; --t)
	{
		flag = 3;
		(void)memset(check, 0, sizeof(check));
		(void)memset(target_r, -1, sizeof(target_r));
		(void)memset(target_c, -1, sizeof(target_c));
		for (init = 0; init < ARCHER; ++init) target_dist[init] = 100;

		for (r = t - 1; r >= t - 1 - D; --r)
		{
			if (r < 0) break;
			for (c = 0; c < M; ++c)
			{
				if (map[r][c])
				{
					for (a = 0; a < ARCHER; ++a)
					{
						ar = t;
						ac = archer[a];
						dr = ar - r;
						dc = ac - c;
						if (dr < 0) dr *= -1;
						if (dc < 0) dc *= -1;
						d = dr + dc;
						if (d <= D && d <= target_dist[a])
						{
							if (target_c[a] >= 0 && target_c[a] < c) continue;
							target_dist[a] = d;
							target_r[a] = r;
							target_c[a] = c;
						}
					}
				}
			}
		}
		for (a = 0; a < ARCHER; ++a)
		{
			r = target_r[a];
			c = target_c[a];
			if (r == -1 || c == -1) continue;
			if (map[r][c])
			{
				map[r][c] = 0;
				cnt++;
			}
		}
	}
	return cnt;
}
inline void set_loca(int cnt, int idx)
{
	if (cnt == ARCHER)
	{
		(void)memcpy(map, map_cpy, sizeof(map));
		//cout << "archer location : ";
		//for (register int p = 0; p < 3; ++p) cout << archer[p] << ' ';
		int tmp = simul();
		if (ret < tmp) ret = tmp;
		return;
	}
	for (register int i = idx; i < M; ++i)
	{
		archer[cnt] = i;
		set_loca(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input17135.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> D;
	ret = 0;
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cin >> map[r][c];
			map_cpy[r][c] = map[r][c];
		}
	}
	set_loca(0, 0);
	cout << ret;
	return 0;
}
