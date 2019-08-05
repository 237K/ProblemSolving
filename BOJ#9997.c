//
//	OS Windows
//	2019.08.04
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #9997 [bitmask] ÆùÆ®
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
char word[26][101];
int check[26];
int N;
int bitmask()
{
	register int ret = 0, cnt, mask, flag, i;
	for (mask = 1; mask < (1 << N); ++mask)
	{
		(void)memset(check, 0, sizeof(check)); cnt = 0;
		for (flag = 0; flag < N; ++flag)
		{
			if ((mask & (1 << flag)))
			{
				//printf("%s ", word[flag]);
				for (i = 0; word[flag][i]; ++i)
				{
					int cur = word[flag][i] - 'a';
					if (!check[cur])
					{
						check[cur] = 1;
						cnt++;
					}
				}
			}
			if (cnt == 26)
			{
				ret++;
				break;
			}
		}
		//printf("|| cnt : %d\n\n", cnt);
	}
	return ret;
}
int main(void)
{
	freopen("input9997.txt", "r", stdin);
	register int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; ++i) scanf("%s", &word[i]);
	printf("%d", bitmask());
	return 0;
}