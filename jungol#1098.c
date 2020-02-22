//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1098> 숫자출력
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 51
char input[SZ];
int trans(char c)
{
	int cnt;
	if (c == '0' || c == '6' || c == '9') cnt = 6;
	else if (c == '1') cnt = 2;
	else if (c == '2' || c == '3' || c == '5') cnt = 5;
	else if (c == '4') cnt = 4;
	else if (c == '7') cnt = 3;
	else if (c == '8') cnt = 7;
	return cnt;
}
int main(void)
{
	register int i, ret = 0;
	scanf("%s", &input);
	for (i = 0; input[i]; ++i)
	{
		ret += trans(input[i]);
	}
	printf("%d", ret);
	return 0;
}