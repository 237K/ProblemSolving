//
//	OS Windows
//	2020.04.14
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1559> Multi Number
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define T 4
int mul(int n)
{
	register int i = 1;
	while (n)
	{
		i *= n % 10;
		n /= 10;
	}
	return i;
}
int comp(int n)
{
	register int i = 1, quo, rmd, left, right, flag = 0;
	while (1)
	{
		i *= 10;
		quo = n / i;
		if (!quo) break;
		rmd = n % i;
		left = mul(quo);
		if (((rmd * 10) < i)) right = 0;
		else right = mul(rmd);
		if (left == right)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main(void)
{
	freopen("jinput1559.txt", "r", stdin);
	int t, N;
	for (t = 0; t < T; ++t)
	{
		scanf("%d", &N);
		if (comp(N)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}