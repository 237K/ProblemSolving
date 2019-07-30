//
//	OS Windows
//	2019.07.30
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3975] (D3) ½Â·ü ºñ±³ÇÏ±â
//
#include <stdio.h>
int main(void)
{
	freopen("s_input3975.txt", "r", stdin);
	int T, A, B, C, D;
	register int tc;
	double a, b;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d %d %d", &A, &B, &C, &D);
		a = ((double)A / (double)B);
		b = ((double)C / (double)D);
		printf("#%d ", tc);
		if (a == b) printf("DRAW\n");
		else if (a < b) printf("BOB\n");
		else printf("ALICE\n");
	}
	return 0;
}