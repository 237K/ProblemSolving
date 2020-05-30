//
//	OS Windows
//	2020.05.30
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2107> 축구
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N, n, win, lose, tie, cur, top = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d %d", &win, &lose, &tie);
		cur = (win * 3) + lose;
		if (top < cur) top = cur;
	}
	printf("%d", top);
	return 0;
}