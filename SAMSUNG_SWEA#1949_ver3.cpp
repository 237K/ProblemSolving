//
//	OS Windows
//	2019.08.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1949] (모의) 등산로 조성
//
//	ver.3
//

#include <iostream>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 8;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ];
static int check[SZ][SZ];
static pii starting[5];
static int T, N, K, max_height, max_height_num, ret;
inline void recur(int r, int c, int len, int dig)
{
	if (ret < len) ret = len;
	for (register int d = 0; d < DIR; ++d)
	{
		int nr = r + dir[d][0];
		int nc = c + dir[d][1];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc]) continue;
		if (map[r][c] <= map[nr][nc])
		{
			if (map[nr][nc] - map[r][c] < dig)
			{
				int tmp = map[nr][nc];
				map[nr][nc] = map[r][c] - 1;
				check[nr][nc] = 1;
				recur(nr, nc, len + 1, -1);
				map[nr][nc] = tmp;
				check[nr][nc] = 0;
			}
		}
		else
		{
			check[nr][nc] = 1;
			recur(nr, nc, len + 1, dig);
			check[nr][nc] = 0;
		}
	}
}
inline void simul()
{
	register int r, c, i;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (max_height == map[r][c])
			{
				starting[max_height_num++] = { r, c };
			}
		}
	}
	for (i = 0; i < max_height_num; ++i)
	{
		(void)memset(check, 0, sizeof(check));
		check[starting[i].first][starting[i].second] = 1;
		recur(starting[i].first, starting[i].second, 1, K);
	}
}
int main(int argc, char** argv)
{
	freopen("s_input1949.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, r, c;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		max_height = max_height_num = ret = 0;
		cin >> N >> K;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				cin >> map[r][c];
				if (max_height < map[r][c]) max_height = map[r][c];
			}
		}
		simul();
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}
