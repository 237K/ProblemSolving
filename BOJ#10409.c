//
//	OS Windows
//	2019.11.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10409	¼­¹ö
//	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N, T, n, tmp, acc = 0, ret = 0;
	scanf("%d %d", &N, &T);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &tmp);
		acc += tmp;
		if (acc <= T) ret++;
		else break;
	}
	printf("%d", ret);
	return 0;
}