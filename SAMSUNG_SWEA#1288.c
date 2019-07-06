//
//	OS Windows
//	2019.07.03
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1288] (D2) 새로운 불면증 치료법
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 10
int T, N;
int check[MAX];
int sep(int cur)
{
	register int quo, rmd, cnt = 0;
	quo = cur;
	while (1)
	{
		rmd = quo % 10;
		if (!check[rmd])
		{
			check[rmd] = 1;
			cnt++;
		}
		quo /= 10;
		if (!quo) break;
	}
	return cnt;
}
int main(void)
{
	freopen("s_input1288.txt", "r", stdin);
	int cur;
	register int tc, n, count;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(check, 0, sizeof(check));
		scanf("%d", &N);
		count = 0; n = 1;
		while (1)
		{
			cur = N * n;
			count += sep(cur);
			if (count == 10) break;
			n++;
		}
		printf("#%d %d\n", tc, cur);
	}
	return 0;
}