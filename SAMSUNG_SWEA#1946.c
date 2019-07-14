//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1946] (D2) 간단한 압축 풀기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
char ret[MAX][MAX];
int main(void)
{
	freopen("s_input1946.txt", "r", stdin);
	int T, N, num;
	char ch;
	register int tc, i, j, idx, r, pr, pc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d\n", &N);
		idx = r = 0;
		for (i = 0; i < N; ++i)
		{
			scanf("%c %d\n", &ch, &num);
			for (j = 0; j < num; ++j)
			{
				if (idx > 9)
				{
					r++;
					idx = 0;
				}
				ret[r][idx++] = ch;
			}
		}
		printf("#%d\n", tc);
		for (pr = 0; pr <= r; ++pr)
		{
			for (pc = 0; pc < MAX; ++pc)
				printf("%c", ret[pr][pc]);
			printf("\n");
		}
	}
	return 0;
}