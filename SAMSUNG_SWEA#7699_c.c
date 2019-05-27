//
//	OS Windows
//	2019.05.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7699> (D4) 수지의 수지 맞는 여행
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 21
#define MAX 26
#define DIRECT 4

int dir[DIRECT][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
char map[SZ][SZ];
int check[MAX];
int R, C, ret;

void recur(int depth, int r, int c)
{
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
		recur(1, 1, 1);
		printf("#%d %d\n", test_case, ret);
	}
	return 0;
}