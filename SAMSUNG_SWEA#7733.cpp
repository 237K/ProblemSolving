//
//	OS Windows
//	2019.05.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7733] <치즈 도둑> (D4)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 101;
const static int DIR = 4;

static int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
static int cheeze[SZ][SZ][SZ];
static int N, S;
inline void print(int d)
{
	register int r, c;
	cout << "day : " << d << '\n';
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
			cout << cheeze[d][r][c] << ' ';
		cout << '\n';
	}
}
inline void check(int d, int r, int c)
{
	register int i, nr, nc;
	queue<pii> Q;
	Q.push({ r, c });
	cheeze[d][r][c] = 0;
	while (!Q.empty())
	{
		pii cur = Q.front();
		Q.pop();
		for (i = 0; i < DIR; ++i)
		{
			nr = cur.first + dir[i][0];
			nc = cur.second + dir[i][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || !cheeze[d][nr][nc]) continue;
			else
			{
				Q.push({ nr, nc });
				cheeze[d][nr][nc] = 0;
			}
		}
	}
}
inline int simul()
{
	int ret = 1, tmp = 0;
	register int d, r, c;
	for (d = 1; d <= S; ++d)
	{
		tmp = 0;
		//	요정이 치즈를 먹음
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				if (cheeze[0][r][c] > d) cheeze[d][r][c] = 1;
				else cheeze[d][r][c] = 0;
			}
		}
		//	덩어리 개수 확인
		for (r = 0; r < N; ++r)
			for (c = 0; c < N; ++c)
				if (cheeze[d][r][c]) check(d, r, c), tmp++;
		if (ret < tmp) ret = tmp;
	}
	return ret;
}
int main(void)
{
	freopen("s_input7733.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, tc, r, c;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		S = 0;
		cin >> N;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				cin >> cheeze[0][r][c];
				if (S < cheeze[0][r][c]) S = cheeze[0][r][c];
			}
		}
		cout << "#" << tc << ' ' << simul() << '\n';
	}
	return 0;
}