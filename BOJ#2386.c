//
//	OS Windows
//	2019.12.26
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2386>	도비의 영어 공부
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 252
char str[MAX], ch;
int main(void)
{
	freopen("input2386.txt", "r", stdin);
	register int i, cur, lower, upper, cnt;
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '#') break;
		gets(str);
		cnt = 0;
		lower = ch;
		upper = lower - 32;
		for (i = 0; str[i]; ++i)
		{
			cur = str[i];
			if (cur == lower || cur == upper) cnt++;
		}
		printf("%c %d\n", ch, cnt);
	}
	return 0;
}