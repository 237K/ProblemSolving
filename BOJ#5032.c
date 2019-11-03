//
//	OS Windows
//	2019.11.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5032	Åº»ê À½·á
//	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input5032.txt", "r", stdin);
	int e, f, c, ret = 0;
	scanf("%d %d %d", &e, &f, &c);
	while (1)
	{
		e += f;
		if (e < c) break;
		ret += e / c;
		f = e % c;
		e /= c;
	}
	printf("%d", ret);
	return 0;
}