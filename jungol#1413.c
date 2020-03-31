//
//	OS Windows
//	2020.03.24
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1413> IP주소
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IP 8
#define LEN 33
int mul[IP] = { 128, 64, 32, 16, 8, 4, 2, 1 };
char bit32[LEN];
int main(void)
{
	freopen("jinput1413.txt", "r", stdin);
	scanf("%s", &bit32);
	register int i, add = 0, idx = 0, cnt = 0, cur;
	for (i = 0; bit32[i]; ++i)
	{
		cur = bit32[i] - '0';
		if (idx >= IP)
		{
			printf("%d.", add);
			add = idx = 0;
		}
		if (cur) add += mul[idx];
		idx++;
	}
	printf("%d", add);
	return 0;
}