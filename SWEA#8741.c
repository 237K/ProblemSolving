//	OS Windows
//	2020.06.25
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8741] (D3) 두문자어
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 3
#define LEN 21
char str[LEN];
int main(void)
{
	int T;
	register int tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		printf("#%d ", tc);
		for (n = 0; n < SZ; ++n)
		{
			scanf("%s", &str);
			printf("%c", str[0] - 32);
		}
		printf("\n");
	}
	return 0;
}