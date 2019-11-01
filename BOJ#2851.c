//
//	OS Windows
//	2019.10.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2851	½´ÆÛ¸¶¸®¿À
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
#define COMP 100
int main(void)
{
	freopen("input2851.txt", "r", stdin);
	int tmp;
	register int i, acc = 0, min_diff = 2147000000, diff = 0;
	for (i = 0; i < MAX; ++i)
	{
		scanf("%d", &tmp);
		acc += tmp;
		diff = COMP - acc;
		if (diff < 0) diff *= -1;
		if (min_diff >= diff) min_diff = diff;
		else break;
	}
	printf("%d", acc);
	return 0;
}