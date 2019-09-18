//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #11022 A+B-8
//

#include <stdio.h>
int main(void)
{
	int T, A, B, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", tc, A, B, A + B);
	}
	return 0;
}