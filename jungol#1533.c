//
//	OS Windows
//	2020.04.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1533> 두 수 찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int x, y, a, b;
	scanf("%d %d", &a, &b);
	x = (a + b) / 2;
	y = x - b;
	printf("%d %d", x, y);
	return 0;
}