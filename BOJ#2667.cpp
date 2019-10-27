//
//	OS Windows
//	2019.10.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2667 단지번호붙이기
//
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 26;
const static int DIR = 4;
typedef pair<int, int> pii;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static char map[SZ][SZ];
static int check[SZ][SZ];
static vector<int> vil;
static int N;
inline void simul()
{
	(void)memset(check, 0, sizeof(check));
	vil.clear();
	register int r, c, cr, cc, d, nr, nc, cnt;
	queue<pii> Q;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (map[r][c] == '1' && !check[r][c])
			{
				while (!Q.empty()) { Q.pop(); }
				check[r][c] = 1;
				cnt = 1;
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
						if (map[nr][nc] == '1')
						{
							check[nr][nc] = 1;
							Q.push({ nr, nc });
							cnt++;
						}
					}
				}
				vil.push_back(cnt);
			}
		}
	}
	sort(vil.begin(), vil.end());
	cout << vil.size() << '\n';
	for (vector<int>::size_type i = 0 ; i < vil.size() ; ++i)
		cout << vil[i] << '\n';
}
int main(int argc, char** argv)
{
	freopen("input2667.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r;
	for (r = 0; r < N; ++r)
		cin >> map[r];
	simul();
	return 0;
}