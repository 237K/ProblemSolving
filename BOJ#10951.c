//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10951 A+B-4
//

#include <stdio.h>
int main(void)
{
	freopen("input10951.txt", "r", stdin);
	int A, B;
	while (1)
	{
		A = B = 0;
		scanf("%d %d", &A, &B);
		if (!A || !B) break;
		printf("%d\n", A + B);
	}
	return 0;
}