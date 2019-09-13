//
//	OS Windows
//	2019.09.14
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10952 A+B-5
//

#include <stdio.h>
int main(void)
{
	int A, B;
	while (1)
	{
		scanf("%d %d", &A, &B);
		if (!A && !B) break;
		printf("%d\n", A + B);
	}
	return 0;
}