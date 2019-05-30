//
//	OS Windows
//	2019.05.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5356] (D3) 의석이의 세로로 말해요
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int main(void)
{
	freopen("s_input5356.txt", "r", stdin);
	char ch[5][15];
	int check[5];
	int T;
	register int tc, i, j;
	scanf("%d\n", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(check, 0, sizeof(check));
		for (i = 0; i < 5; ++i)
		{
			ch[i][0] = ' ';
			scanf("%s\n", &ch[i]);
		}
		printf("#%d ", tc);
		for (j = 0; j < 15; ++j)
		{
			for (i = 0; i < 5; ++i)
			{
				if (!check[i])
				{
					if ((ch[i][j] >= 'A' && ch[i][j] <= 'Z') || (ch[i][j] >= 'a' && ch[i][j] <= 'z') || (ch[i][j] >= '0' && ch[i][j] <= '9'))
					{
						printf("%c", ch[i][j]);
					}
					else check[i] = 1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}