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
#include <memory.h>
using namespace std;
const static int SZ = 1001;
const static int DIR = 4;
static int dir[DIR][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static char map[SZ][SZ];
static int check[SZ][SZ];
static int N, M, ret;
inline void recur(int r, int c, int cnt, int flag)
{
	if (r == N - 1 && c == M - 1)
	{
		if (ret > cnt) ret = cnt;
		return;
	}
	if (ret < cnt) return;
	for (register int d = 0; d < DIR; ++d)
	{
		int nr = r + dir[d][0];
		int nc = c + dir[d][1];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M || check[nr][nc]) continue;
		if (map[nr][nc] == '1')
		{
			if (flag) flag = 0;
			else continue;
		}
		check[nr][nc] = 1;
		recur(nr, nc, cnt + 1, flag);
		check[nr][nc] = 0;
	}
}
int main(int argc, char** argv)
{
	freopen("input2206.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r;
	ret = 2147000000;
	(void)memset(check, 0, sizeof(check));
	cin >> N >> M;
	for (r = 0; r < N; ++r) cin >> map[r];
	check[0][0] = 1;
	recur(0, 0, 1, 1);
	if (ret == 2147000000) ret = -1;
	cout << ret;
	return 0;
}