//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2702>	초6 수학
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int T, A, B, upper, lower, GCD, CM;
int main(void)
{
	freopen("input2702.txt", "r", stdin);
	register int i, tc;
	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc)
	{
		scanf("%d %d", &A, &B);
		if (A > B)
		{
			upper = A;
			lower = B;
		}
		else
		{
			upper = B;
			lower = A;
		}
		for (i = lower; i >= 1; --i)
		{
			if (!(A % i) && !(B % i))
			{
				GCD = i;
				break;
			}
		}
		i = upper;
		CM = 0;
		while (i < upper * lower)
		{
			if (!(i % A) && !(i % B))
			{
				CM = i;
				break;
			}
			i += GCD;
		}
		if (!CM) CM = upper * lower;
		printf("%d %d\n", CM, GCD);
	}
	return 0;
}