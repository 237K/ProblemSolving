//
//	OS Windows
//	2020.02.11
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1144> ����ã��
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
char hint[SZ];
int main(void)
{
	freopen("jinput1144.txt", "r", stdin);
	int x, y, i;
	scanf("%d %d %s", &x, &y, &hint);
	for (i = 0; hint[i]; ++i)
	{
		if (hint[i] == 'U') y++;
		else if (hint[i] == 'D') y--;
		else if (hint[i] == 'L') x--;
		else x++;
	}
	printf("%d %d", x, y);
	return 0;
}