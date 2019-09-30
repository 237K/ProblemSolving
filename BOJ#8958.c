//
//	OS Windows
//	2019.09.29
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #8958 OXÄûÁî
//

#include <stdio.h>
char input[82];
int main(void)
{
	freopen("input8958.txt", "r", stdin);
	int T;
	register int i, tc, cnt, ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		cnt = ret = 0;
		input[0] = '\0';
		scanf("%s", &input);
		for (i = 0; input[i]; ++i)
		{
			if (input[i] == 'O') cnt++;
			else cnt = 0;
			ret += cnt;
		}
		printf("%d\n", ret);
	}
	return 0;
}