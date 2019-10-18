//
//	OS Windows
//	2019.09.21
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2753 À±³â
//

#include <stdio.h>
int main(void)
{
	int N, ret = 0, i;
	scanf("%d", &N);
	if (!(N % 400)) ret = 1;
	if (!(N % 4) && N % 100) ret = 1;
	printf("%d", ret);
	return 0;
}