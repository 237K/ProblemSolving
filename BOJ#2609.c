//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2609>	최대공약수와 최소공배수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int A, B, upper, lower, GCD, CM;
int main(void)
{
	freopen("input2609.txt", "r", stdin);
	scanf("%d %d", &A, &B);
	register int i;
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
	printf("%d\n%d", GCD, CM);
	return 0;
}