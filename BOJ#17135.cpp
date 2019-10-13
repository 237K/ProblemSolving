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
static int archer[ARCHER], check[ARCHER];
static int map[SZ][SZ], map_cpy[SZ][SZ];
static int N, M, D, ret;
inline void print()
{
	register int r, c;
	cout << "==========================================\n\n";
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < M; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "==========================================\n\n";
}
inline int simul()
{
	register int t, r, c, d, a, ar, ac, flag, cnt = 0;
	for (t = N; t > 0; --t)
	{
	
		cout << "archer location : ";
		for (register int i = 0; i < 3; ++i) cout << archer[i] << ' ';
		cout << "\n\n*turn "<<t<<"\n\n";
		print();


		flag = 3;
		(void)memset(check, 0, sizeof(check));
		for(r = t-1 ; r >= t - 1 - D ; --r)
		{
			if (r < 0) break;
			if (!flag) break;
			for (c = 0; c < M; ++c)
			{
				if (map[r][c])
				{
					for (a = 0; a < ARCHER; ++a)
					{
						if (!check[a])
						{
							ar = t;
							ac = archer[a];
							d = (ar - r) + (ac - c);
							if (d < 0) d *= -1;
							if (d <= D)
							{
								check[a] = 1;
								flag--;
								cnt++;
								map[r][c] = 0;
							}
						}
					}
				}
			}
		}
		print();
	}
	return cnt;
}
inline void set_loca(int cnt, int idx)
{
	if (cnt == ARCHER)
	{
		(void)memcpy(map, map_cpy, sizeof(map));
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
