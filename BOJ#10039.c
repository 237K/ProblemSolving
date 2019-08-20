//
//	OS Windows
//	2019.08.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10039	Æò±Õ Á¡¼ö
//

#include <stdio.h>
int main(void)
{
	int A, i, sum = 0;
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &A);
		if (A < 40) A = 40;
		sum += A;
	}
	printf("%d", sum / 5);
	return 0;
}