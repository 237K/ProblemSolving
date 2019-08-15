//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2577	숫자의 개수
//

#include <stdio.h>
#include <memory.h>
int num[10];
int A, B, C, N, rmd, i;
int main(void)
{
	(void)memset(num, 0, sizeof(num));
	scanf("%d\n%d\n%d", &A, &B, &C);
	N = A * B * C;
	while (N)
	{
		rmd = N % 10;
		num[rmd]++;
		N /= 10;
	}
	for (i = 0; i < 10; ++i) printf("%d\n", num[i]);
	return 0;
}