//
//	OS Windows
//	2019.06.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4047] (D3) 영준이의 카드 카운팅
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
char input[1001];
int card[4][14];
int card2[4];
int main(void)
{
	freopen("s_input4047.txt", "r", stdin);
	int T;
	register int tc, i, kind, num, a, b, ret, p;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		kind = -1; ret = 1;
		(void)memset(card, 0, sizeof(card));
		(void)memset(card2, 0, sizeof(card2));
		scanf("%s", &input);
		for (i = 0; input[i]; i+=3)
		{
			if (input[i] == 'S') kind = 0;
			else if (input[i] == 'D') kind = 1;
			else if (input[i] == 'H') kind = 2;
			else if (input[i] == 'C') kind = 3;

			if (kind >= 0)
			{
				a = input[i + 1] - '0';
				b = input[i + 2] - '0';
				num = a * 10 + b;
				if (card[kind][num])
				{
					ret = 0;
					break;
				}
				else
				{
					card[kind][num] = 1;
					card2[kind]++;
				}
			}
		}
		if (!ret) printf("#%d ERROR\n", tc);
		else
		{
			printf("#%d ", tc);
			for (p = 0; p < 4; ++p)
			{
				printf("%d ", 13 - card2[p]);
			}
			printf("\n");
		}
	}
	return 0;
}