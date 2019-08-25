//
//	OS Windows
//	2019.08.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5532	¹æÇÐ ¼÷Á¦
//

#include <stdio.h>
int main(void)
{
	int L, A, B, C, D, quo1, quo2, rmd1, rmd2, ret;
	scanf("%d\n%d\n%d\n%d\n%d", &L, &A, &B, &C, &D);
	quo1 = A / C; rmd1 = A % C; if (rmd1) quo1++;
	quo2 = B / D; rmd2 = B % D; if (rmd2) quo2++;
	if (quo1 >= quo2) ret = quo1;
	else ret = quo2;
	L -= ret;
	printf("%d", L);
	return 0;
}