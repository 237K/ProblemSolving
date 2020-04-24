//
//	OS Windows
//	2020.04.18
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1658> 최대공약수(GCD)와 최소공배수(LCM)
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_GCD(int high, int low)
{
	register int i;
	for (i = low; i >= 1; --i)
	{
		if (!(high % i) && !(low % i))
			break;
	}
	return i;
}
int get_LCM(int gcd, int high, int low)
{
	register int i, max;
	max = high * low;
	for (i = high; i <= max; i+=gcd)
	{
		if (!(i % high) && !(i % low))
			break;
	}
	return i;
}
int main(void)
{
	freopen("jinput1658.txt", "r", stdin);
	int one, two, h, l, gcd, lcm;
	scanf("%d %d", &one, &two);
	if (one > two)
	{
		h = one;
		l = two;
	}
	else
	{
		h = two;
		l = one;
	}
	gcd = get_GCD(h, l);
	lcm = get_LCM(gcd, h, l);
	printf("%d\n%d", gcd, lcm);
	return 0;
}