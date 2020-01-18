//
//	OS Windows
//	2020.01.06
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2566>	최댓값
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10
int main(void)
{
	int cur, r, c, m = 0, mr, mc;
	for (r = 1; r < SZ; ++r)
	{
		for (c = 1; c < SZ; ++c)
		{
			scanf("%d", &cur);
			if (m < cur)
			{
				m = cur;
				mr = r;
				mc = c;
			}
		}
	}
	printf("%d\n%d %d", m, mr, mc);
	return 0;
}