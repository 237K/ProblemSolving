//
//	OS Windows
//	2019.11.26
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #1264>	모음의 개수
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 256
char ch[SZ];
int cnt()
{
	register int i, c = 0;
	for (i = 0; ch[i]; ++i)
	{
		if (ch[i] == 'a' || ch[i] == 'A' || ch[i] == 'e' || ch[i] == 'E' ||
			ch[i] == 'i' || ch[i] == 'I' || ch[i] == 'o' || ch[i] == 'O' ||
			ch[i] == 'u' || ch[i] == 'U') c++;
	}
	return c;
}
int main(void)
{
	freopen("input1264.txt", "r", stdin);
	while (1)
	{
		gets(ch);
		if (ch[0] == '#') break;
		printf("%d\n", cnt());
	}
	return 0;
}