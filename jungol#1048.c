//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1048> 팩토리얼1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N, ret;
	scanf("%d", &N);
	if (N <= 4) ret = 0;
	else if (N <= 9) ret = 1;
	else if (N <= 14) ret = 2;
	else if (N <= 19) ret = 3;
	else ret = 4;
	printf("%d", ret);
	return 0;
}