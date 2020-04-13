//
//	OS Windows
//	2020.04.12
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1584> EMIRPS
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check_prime(int n)
{
	register int i, flag = 1;
	for (i = 2; i < n; ++i)
	{
		if (!(n % i))
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int reverse(int n)
{
	register int i = 0;
	while (n)
	{
		i *= 10;
		i += n % 10;
		n /= 10;
	}
	return i;
}
int simul(int n)
{
	register int re, flag;
	re = reverse(n);
	if (check_prime(n))
	{
		if (check_prime(re))
			flag = 2;
		else
			flag = 1;
	}
	else
		flag = 0;
	return flag;
}
int main(void)
{
	freopen("jinput1584.txt", "r", stdin);
	int N, ret;
	scanf("%d", &N);
	ret = simul(N);
	if (!ret) printf("not prime number");
	else if (ret == 1) printf("prime number");
	else printf("emirp");
	return 0;
}