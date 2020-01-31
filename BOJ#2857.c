//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2857>	FBI
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 13
#define T 5
char input[SZ];
int main(void)
{
	freopen("input2857.txt", "r", stdin);
	register int tc, i, flag = 0;
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%s", &input);
		for (i = 0; input[i]; ++i)
		{
			if (input[i] == 'F')
			{
				if (input[i + 1] == 'B' && input[i + 2] == 'I')
				{
					flag++;
					printf("%d ", tc);
					break;
				}
			}
		}
	}
	if (!flag) printf("HE GOT AWAY!");
	return 0;
}