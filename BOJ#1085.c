//
//	OS Windows
//	2019.08.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1085	직사각형에서 탈출
//

#include <stdio.h>
int main(void)
{
	freopen("input1085.txt", "r", stdin);
	int x, y, w, h, ret;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if (x > y) ret = y;
	else ret = x;
	if (ret > w - x) ret = w - x;
	if (ret > h - y) ret = h - y;
	printf("%d", ret);
	return 0;
}