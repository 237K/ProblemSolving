//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1056> 일의자리 3의 배수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N, M, i, num, cnt = 0;
	scanf("%d %d", &N, &M);
	for (i = N; i <= M; ++i)
	{
		num = i % 10;
		if (!num) continue;
		if (!(num % 3))
		{
			printf("%d\n", i);
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}