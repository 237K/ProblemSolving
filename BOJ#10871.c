//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10871	X보다 작은 수
//

#include <stdio.h>
int main(void)
{
	int N, X, A, i;
	scanf("%d %d", &N, &X);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		if (X > A) printf("%d ", A);
	}
	return 0;
}