//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1976] (D2) ½Ã°¢ µ¡¼À
//

#include <stdio.h>
int main(void)
{
	int T, H1, M1, H2, M2;
	register int tc, h, m;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		h = m = 0;
		scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
		m = M1 + M2;
		h += m / 60; m %= 60;
		h += (H1 + H2) % 12;
		if (!h) h = 12;
		printf("#%d %d %d\n", tc, h, m);
	}
	return 0;
}