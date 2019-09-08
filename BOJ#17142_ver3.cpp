//
//	OS Windows
//	2019.09.06
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17142	¿¬±¸¼Ò3
//
//	ver.3
//

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 51;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], map_cpy[SZ][SZ];
static int N, M, num_virus, num_empty, ret;
static pii virus[251];
static int selected[10];
//inline void print()
//{
//	register int r, c;
//	cout << "====================================\n\n";
//	for (r = 0; r < N; ++r)
//	{
//		for (c = 0; c < N; ++c)
//		{
//			cout << map[r][c] << "  ";
//		}
//		cout << "\n\n";
//	}
//	cout << "====================================\n\n";
//}
inline int simul()
{
	register int i, sz, time = 0, cr, cc, d, nr, nc, return_value = -1, spread = 0, end_flag = 0;
	queue<pii> Q;
	for (i = 0; i < M; ++i)
	{
		Q.push({ virus[selected[i]] });
		map[virus[selected[i]].first][virus[selected[i]].second] = -1;
	}
	while (!Q.empty())
	{
		if(num_empty)
		if (ret < ++time) return -1;
		//cout << "time : " << time << "\n\n";
		//print();

		sz = Q.size();
		while (sz--)
		{
			cr = Q.front().first;
			cc = Q.front().second;
			Q.pop();
			for (d = 0; d < DIR; ++d)
			{
				nr = cr + dir[d][0];
				nc = cc + dir[d][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc] == 1 || map[nr][nc] < 0) continue;
				if (!map[nr][nc]) spread++;
				Q.push({ nr, nc });
				map[nr][nc] = -1;
			}
		}
		if (spread == num_empty)
		{
			end_flag = 1;
			break;
		}
	}
	if (end_flag) return_value = time;
	else return_value = -1;
	return return_value;
}
inline void recur(int cnt, int idx)
{
	if (cnt == M)
	{
		(void)memcpy(map, map_cpy, sizeof(map));

		//for (register int p = 0; p < M; ++p) cout << selected[p] << ' ';
		//cout << "\n\n";

		int tmp = simul();
		if (tmp > 0 && ret > tmp) ret = tmp;
		return;
	}
	for (register int i = idx; i < num_virus; ++i)
	{
		selected[cnt] = i;
		recur(cnt + 1, i + 1);
	}
}

int main(int argc, char** argv)
{
	freopen("input17142.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	ret = 2147000000; num_empty = 0;
	cin >> N >> M;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map_cpy[r][c];
			if (!map_cpy[r][c]) num_empty++;
			else if (map_cpy[r][c] == 2) virus[num_virus++] = { r, c };
		}
	}
	if (!num_empty) ret = 0;
	else recur(0, 0);
	if (ret == 2147000000) ret = -1;
	cout << ret;
	return 0;
}