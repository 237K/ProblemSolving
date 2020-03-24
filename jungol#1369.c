//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1369> 메이플 스토리
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TIME 600
#define SZ 10
int main(void)
{
	freopen("jinput1369.txt", "r", stdin);
	int T, tc, i, d, dps, boss;
	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc)
	{
		dps = 0;
		scanf("%d", &boss);
		for (i = 0; i < SZ; ++i)
		{
			scanf("%d", &d);
			dps += d;
		}
		dps *= TIME;
		if (dps >= boss) printf("KILL\n");
		else printf("NO\n");
	}
	return 0;
}