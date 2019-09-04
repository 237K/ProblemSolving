//
//	OS Windows
//	2019.09.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2070] (D1) Å« ³ð, ÀÛÀº ³ð, °°Àº ³ð
//

#include <stdio.h>
int main(void)
{
	int T, tc, A, B;
	char ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &A, &B);
		if (A == B) ret = '=';
		else if (A < B) ret = '<';
		else ret = '>';
		printf("#%d %c\n", tc, ret);
	}
	return 0;
}