//
//	OS Windows
//	2019.11.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #6321	IBM »©±â 1
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input6321.txt", "r", stdin);
	int T, tc, i;
	char str[51];
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		str[0] = '/0';
		scanf("%s", &str);
		printf("String #%d\n", tc);
		for (i = 0; str[i]; ++i)
		{
			if (str[i] == 'Z') printf("A");
			else printf("%c", str[i] + 1);
		}
		printf("\n\n");
	}
	return 0;
}