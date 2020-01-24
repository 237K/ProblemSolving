//
//	OS Windows
//	2019.10.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2206	벽 부수고 이동하기
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> pp;		//	{ {row, col}, {count, flag} }
const static int SZ = 1001;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static char map[SZ][SZ];
static int check[SZ][SZ][2];
static int N, M;
inline int simul()
{
	register int cr, cc, nr, nc, d, cnt, flag, tmp_flag, ret = 0;
	queue<pp> Q;
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	Q.push({ {0, 0}, {1, 1} });
	check[0][0][1] = 1;
	while (!Q.empty())
	{
		cr = Q.front().first.first;
		cc = Q.front().first.second;
		cnt = Q.front().second.first;
		flag = Q.front().second.second;
		Q.pop();

		if (cr == N - 1 && cc == M - 1)
		{
			ret = cnt;
			break;
		}
		tmp_flag = flag;
		for (d = 0; d < DIR; ++d)
		{
			flag = tmp_flag;
			nr = cr + dir[d][0];
			nc = cc + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || check[nr][nc][flag]) continue;
			if (map[nr][nc] == '1')
			{
				if (flag) flag = 0;
				else continue;
			}
			cout << "(" << nr << ", " << nc << ") cnt : "<<cnt<<"   flag : "<<flag<<"\n";
			Q.push({ {nr, nc}, {cnt + 1, flag} });
			check[nr][nc][flag] = 1;
		}
	}
	if (!ret) ret = -1;
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input2206.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r;
	cin >> N >> M;
	for (r = 0; r < N; ++r) cin >> map[r];
	cout << simul();
	return 0;
}