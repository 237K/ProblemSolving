//
//	OS Windows
//	2019.05.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2105> 디저트 카페 (모의)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const static int DIRECT = 4;
const static int SZ = 20;
const static int ROUTE = SZ * 2;

static int dir[DIRECT][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
static int map[SZ][SZ];
static int route[ROUTE];
static int T, N, max_len, cur_len;
inline void print_route(int l)
{
	for (register int i = 0; i < l; ++i)
		cout << route[i] << ' ';
	cout << "\n\n";
}
inline void dfs(int start_r, int start_c, int r, int c, int d, int len)
{
	if (len > 0 && start_r == r && start_c == c)
	{
		if (len > cur_len) cur_len = len;
		return;
	}
	if (r < 0 || r > N - 1 || c < 0 || c > N - 1)
		return;
	if (d > 3)
		return;
	for (register int i = 0; i < len; ++i)
	{
		if (route[i] == map[r][c])
			return;
	}

	route[len] = map[r][c];
	int nr = r + dir[d][0];
	int nc = c + dir[d][1];
	int xnr = r + dir[d + 1][0];
	int xnc = c + dir[d + 1][1];
	dfs(start_r, start_c, nr, nc, d, len + 1);
	dfs(start_r, start_c, xnr, xnc, d + 1, len + 1);
}
inline int simulation()
{
	max_len = 0; cur_len = 0;
	register int r, c;
	for (r = 0; r < N - 2; ++r)
	{
		for (c = 1; c < N - 1; ++c)
		{
			(void)memset(route, 0, sizeof(route));
			dfs(r, c, r, c, 0, 0);
			if (max_len < cur_len) max_len = cur_len;
		}
	}
	if (!max_len) max_len = -1;
	return max_len;
}
int main(int argc, char** argv)
{
	freopen("s_input2105.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int test_case, r, c;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				cin >> map[r][c];
			}
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}