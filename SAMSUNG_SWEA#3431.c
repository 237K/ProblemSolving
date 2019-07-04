//
//	OS Windows
//	2019.07.03
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3431] (D3) 준환이의 운동관리
//

#include <stdio.h>
int main(void)
{
	int T, L, U, X;
	register int tc, ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d %d", &L, &U, &X);
		if (X > U) ret = -1;
		else if (X >= L) ret = 0;
		else ret = L - X;
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}