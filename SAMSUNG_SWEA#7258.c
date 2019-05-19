//
//	OS Windows
//	2019.05.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7258> (D5) 혁진이의 프로그램 검증
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

#define SZ 20
#define DIRECT 4
#define MAX 16

char map[SZ][SZ];
int check[SZ][SZ][DIRECT][MAX];
int dir[DIRECT][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int T, R, C;
int cr, cc, cd, mem;

int test()
{
	char inst;
	int flag = 0;
	while (1)
	{
		//printf("(%d, %d) ", cr, cc);
		if (check[cr][cc][cd][mem])
			return 0;
		
		check[cr][cc][cd][mem] = 1;

		inst = map[cr][cc];

		if (inst == '@')
			return 1;

		if (inst == '<')
			cd = 3;
		else if (inst == '>')
			cd = 1;
		else if (inst == '^')
			cd = 0;
		else if (inst == 'v')
			cd = 2;
		else if (inst == '_')
		{
			if (!mem) cd = 1;
			else cd = 3;
		}
		else if (inst == '|')
		{
			if (!mem) cd = 2;
			else cd = 0;
		}
		else if (inst == '?')
		{
			for (register int d = 0; d < DIRECT; ++d)
			{
				int temp_cr = cr;
				int temp_cc = cc;
				int temp_cd = cd;
				if (check[cr][cc][d][mem]) continue;
				
				int nr = (cr + dir[d][0]);
				int nc = (cc + dir[d][1]);
				if (nr < 0) nr = R - 1;
				else if (nr > R - 1) nr = 0;
				if (nc < 0) nc = C - 1;
				else if (nc > C - 1) nc = 0;
				if (map[nr][nc] == '@')
					return 1;
				else
				{
					cr = nr;
					cc = nc;
					cd = d;
					flag = test();
					cr = temp_cr;
					cc = temp_cc;
					cd = temp_cd;
					if (flag) return 1;
				}
			}
		}
		else if (inst >= '0' && inst <= '9')
		{
			mem = inst - '0';
		}
		else if (inst == '+')
		{
			mem = (mem + 1) % 16;
		}
		else if (inst == '-')
		{
			mem -= 1;
			if (mem < 0) mem = 15;
		}

		cr = (cr + dir[cd][0]);
		cc = (cc + dir[cd][1]);
		if (cr < 0) cr = R - 1;
		else if (cr > R - 1) cr = 0;
		if (cc < 0) cc = C - 1;
		else if (cc > C - 1) cc = 0;
	}
	return flag;
}

int main(int argc, char** argv)
{
	freopen("s_input7258.txt", "r", stdin);
	setbuf(stdout, NULL);
	register int test_case, r;
	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(check, 0, sizeof(check));
		cr = 0; cc = 0; cd = 1; mem = 0;
		scanf("%d %d\n", &R, &C);
		for (r = 0; r < R; ++r)
			scanf("%s", &map[r]);

		if (test())
			printf("#%d YES\n", test_case);
		else
			printf("#%d NO\n", test_case);
	}
	return 0;
}