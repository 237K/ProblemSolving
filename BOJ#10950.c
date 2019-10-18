//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10950 A+B-3
//

#include <stdio.h>
int main(void)
{
	int T, A, B, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}
	return 0;
}