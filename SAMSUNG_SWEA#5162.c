//
//	OS Windows
//	2019.06.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5162] (D3) µÎ °¡Áö »§ÀÇ µô·¹¸¶
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("s_input5162.txt", "r", stdin);
	int T, A, B, C, D;
	register int tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d %d", &A, &B, &C);
		D = A > B ? A : B;
		printf("#%d %d\n", tc, C / D);
	}
	return 0;
}