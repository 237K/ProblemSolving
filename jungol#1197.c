//
//	OS Windows
//	2020.03.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1197> 반복되는 패턴 찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define LEN 1001
char arr[LEN];
int cnt[LEN];
int main(void)
{
	freopen("jinput1197.txt", "r", stdin);
	(void)memset(cnt, 0, sizeof(cnt));
	register int i, c, len;
	scanf("%s", &arr);
	c = len = 0;
	for (i = 0; arr[i]; ++i)
	{
		len++;
		if (arr[i] - '0')
		{
			c++;
		}
		else
		{
			cnt[c]++;
			c = 0;
		}
	}
	cnt[c]++;
	for (i = 1; i <= len; ++i)
	{
		if (cnt[i])
			printf("%d : %d\n", i, cnt[i]);
	}
	return 0;
}