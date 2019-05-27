//
//	OS Windows
//	2019.05.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7699> (D4) 수지의 수지 맞는 여행
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <memory.h>
using namespace std;

const static int SZ = 21;
const static int MAX = 26;
const static int DIRECT = 4;

static int dir[DIRECT][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
static char map[SZ][SZ];
static int check[MAX];
static int R, C, ret;
static string route, temp;

inline void recur(int depth, int r, int c)
{
	//printf("(%d, %d) ", r, c);
	if (ret < depth)
		ret = depth;

	for (register int d = 0; d < DIRECT; ++d)
	{
		int nr = r + dir[d][0];
		int nc = c + dir[d][1];
		if (nr < 1 || nc < 1 || nr > R || nc > C)
			continue;
		if (!check[map[nr][nc] - 'A'])
		{
			check[map[nr][nc] - 'A'] = 1;
			recur(depth + 1, nr, nc);
			check[map[nr][nc] - 'A'] = 0;
			//printf("\n");
		}
	}
}
int main(int argc, char** argv)
{
	freopen("s_input7699.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	register int test_case, r, c;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(check, 0, sizeof(check));
		ret = 0;

		scanf("%d %d\n", &R, &C);
		for (r = 1; r <= R; ++r)
		{
			for (c = 1; c <= C; ++c)
			{
				scanf("%c", &map[r][c]);
			}
			scanf("\n");
		}
		check[map[1][1] - 'A'] = 1;
		route = map[1][1];	temp = map[1][1];
		recur(1, 1, 1);
		printf("#%d %d\n", test_case, ret);
	}
	return 0;
}