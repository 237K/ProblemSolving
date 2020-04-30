//
//	OS Windows
//	2020.04.24
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1721> ¿Ü°è°ö¼À(alien)
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10
#define MAX 20
int A[SZ], B[SZ], a, b, num_A, num_B;
void dep()
{
	num_A = num_B = 0;
	while (a)
	{
		A[num_A++] = a % 10;
		a /= 10;
	}
	while (b)
	{
		B[num_B++] = b % 10;
		b /= 10;
	}
}
int mul()
{
	register int ret = 0, i, j;
	for (i = 0; i < num_A; ++i)
	{
		for (j = 0; j < num_B; ++j)
		{
			ret += A[i] * B[j];
		}
	}
	return ret;
}
int main(void)
{
	scanf("%d %d", &a, &b);
	dep();
	printf("%d", mul());
	return 0;
}