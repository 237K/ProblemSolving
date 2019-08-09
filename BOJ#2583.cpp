//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2583	영역 구하기
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 101;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ];
static int N, M, K, num_area;
static int ld_row[SZ], ld_col[SZ], ru_row[SZ], ru_col[SZ];
static vector<int> area;
inline void sep()
{
	register int r, c, k;
	for (k = 0; k < K; ++k)
		for (r = 0; r < M; ++r)
			for (c = 0; c < N; ++c)
				if (r >= ld_row[k] && r < ru_row[k] && c >= ld_col[k] && c < ru_col[k])
					map[r][c] = 1;
}
inline void find()
{
	register int r, c, d, nr, nc, size_area;
	stack<pii> ST;
	for (r = 0; r < M; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (!map[r][c])
			{
				num_area++;
				size_area = 1;
				ST.push({ r, c });
				map[r][c] = num_area;
				while (!ST.empty())
				{
					pii cur = ST.top();
					ST.pop();
					for (d = 0; d < DIR; ++d)
					{
						nr = cur.first + dir[d][0];
						nc = cur.second + dir[d][1];
						if (nr < 0 || nc < 0 || nr >= M || nc >= N || map[nr][nc]) continue;
						map[nr][nc] = num_area;
						ST.push({ nr, nc });
						size_area++;
					}
				}
				area.push_back(size_area);
			}
		}
	}
	sort(area.begin(), area.end());
}
int main(int argc, char** argv)
{
	freopen("input2583.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int k;
	(void)memset(map, 0, sizeof(map)); area.clear(); num_area = 0;
	cin >> M >> N >> K;
	for (k = 0; k < K; ++k)	cin >> ld_col[k] >> ld_row[k] >> ru_col[k] >> ru_row[k];
	sep(); find();
	cout << num_area << '\n';
	for (k = 0; k < num_area; ++k) cout << area[k] << ' ';
	return 0;
}