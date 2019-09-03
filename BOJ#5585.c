//
//	OS Windows
//	2019.08.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5585	°Å½º¸§µ·
//

#include <stdio.h>
int main(void)
{
	freopen("input5585.txt", "r", stdin);
	int X, Y, ret = 0;
	scanf("%d", &X);
	Y = 1000 - X;
	ret += Y / 500;
	Y %= 500;
	ret += Y / 100;
	Y %= 100;
	ret += Y / 50;
	Y %= 50;
	ret += Y / 10;
	Y %= 10;
	ret += Y / 5;
	Y %= 5;
	ret += Y;
	printf("%d", ret);
	return 0;
}