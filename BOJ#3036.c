//
//	OS Windows
//	2020.01.21
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #3036>	¸µ
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
int calGCD(int n1, int n2)
{
	register int i, gcd, upper, lower;
	if (n1 > n2)
	{
		upper = n1;
		lower = n2;
	}
	else
	{
		upper = n2;
		lower = n1;
	}
	for (i = lower; i > 0; --i)
	{
		if (!(n1 % i) && !(n2 % i))
		{
			gcd = i;
			break;
		}
	}
	return gcd;
}
int main(void)
{
	int arr[SZ], N, n, GCD;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
		if (!n) continue;
		GCD = calGCD(arr[0], arr[n]);
		printf("%d/%d\n", arr[0] / GCD, arr[n] / GCD);
	}
	return 0;
}