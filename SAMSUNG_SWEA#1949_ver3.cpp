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
#include <stack>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const static int SZ = 8;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ], map_cpy[SZ][SZ];
static int check[SZ][SZ];
static pii starting[5];
static int T, N, K, max_height, max_height_num, ret;
inline void simul()
{
	register int r, c, nr, nc, i, d, dig;
	stack<piii> ST;
	//	시작점 찾기
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (map[r][c] == max_height)
			{
				starting[max_height++] = { r, c };
			}
		}
	}
	//	경로 탐색
	for (i = 0; i < max_height_num; ++i)
	{
		(void)memset(check, 0, sizeof(check));
		(void)memcpy(map_cpy, map, sizeof(map));
		while (!ST.empty()) { ST.pop(); }
		dig = K;
		ST.push({ starting[i], 1 });
		check[starting[i].first][starting[i].second] = 1;
		while (!ST.empty())
		{
			piii cur = ST.top();
			ST.pop();
			pii cur_loc = cur.first;
			int cur_len = cur.second;
			int cur_height = map[cur_loc.first][cur_loc.second];
			if (ret < cur_len) ret = cur_len;
			for (d = 0; d < DIR; ++d)
			{
				nr = cur_loc.first + dir[d][0];
				nc = cur_loc.second + dir[d][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc]) continue;
				if (cur_height <= map[nr][nc])
				{
					if (map[nr][nc] - cur_height <= dig)
					{
						map[nr][nc] = cur_height - 1;
						dig = -1;
					}
					else continue;
				}
				ST.push({ {nr, nc}, cur_len + 1 });
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("s_input1949.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, r, c;
	max_height = max_height_num = ret = 0;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(check, 0, sizeof(check));
		cin >> N >> K;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				cin >> map[r][c];
				map_cpy[r][c] = map[r][c];
				if (max_height < map[r][c]) max_height = map[r][c];
			}
		}
	}
	return 0;
}
