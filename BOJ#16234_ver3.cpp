//
//	OS Windows
//	2019.09.05
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16234	인구 이동
//
//	ver.3
//

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int DIR = 4;
const static int SZ = 51;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int map[SZ][SZ];
static int check[SZ][SZ];
static int N, L, R;
static vector<pii> uni[SZ*SZ];
//inline void print()
//{
//	register int r, c;
//	cout << "===========================================\n\n";
//	for (r = 0; r < N; ++r)
//	{
//		for (c = 0; c < N; ++c)
//		{
//			cout << "   " << map[r][c] << "   ";
//		}
//		cout << "\n\n";
//	}
//	cout << "===========================================\n\n";
//}
inline int simul()
{
	register int i, j, cur, r, c, d, cr, cc, nr, nc, uni_sum, uni_num, nation_num, uni_avg, ret = 0;
	queue<pii> Q;
	while (1)
	{
		//print();
		//	초기화
		uni_num = 0;
		(void)memset(check, 0, sizeof(check));
		for (i = 0; i < N * N; ++i) uni[i].clear();
		//	연합 존재여부 확인
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				if (!check[r][c])
				{
					while (!Q.empty()) { Q.pop(); }
					check[r][c] = 1;
					uni[uni_num].push_back({ r, c });
					Q.push({ r, c });
					while (!Q.empty())
					{
						cr = Q.front().first;
						cc = Q.front().second;
						Q.pop();
						for (d = 0; d < DIR; ++d)
						{
							nr = cr + dir[d][0];
							nc = cc + dir[d][1];
							if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc]) continue;
							cur = map[cr][cc] - map[nr][nc];
							if (cur < 0) cur *= -1;
							if (cur < L || cur > R) continue;
							Q.push({ nr, nc });
							check[nr][nc] = 1;
							uni[uni_num].push_back({ nr, nc });
						}
					}
					uni_num++;
				}
			}
		}
		//	종료 검사
		if (uni_num == N * N) break;

		ret++;
		//	인구이동
		for (i = 0; i < uni_num; ++i)
		{
			if (uni[i].size() > 1)
			{
				nation_num = uni[i].size();
				uni_sum = 0;
				for (j = 0; j < nation_num; ++j)
				{
					uni_sum += map[uni[i][j].first][uni[i][j].second];
				}
				uni_avg = uni_sum / nation_num;
				for (j = 0; j < nation_num; ++j)
				{
					map[uni[i][j].first][uni[i][j].second] = uni_avg;
				}
			}
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input16234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	cin >> N >> L >> R;
	for (r = 0; r < N; ++r)
		for (c = 0; c < N; ++c)
			cin >> map[r][c];
	cout << simul();
	return 0;
}