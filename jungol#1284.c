//
//	OS Windows
//	2020.03.12
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1284> Modulo
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define T 10
int main(void)
{
	int tc, a;
	for (tc = 0; tc < T; ++tc)
	{
		scanf("%d", &a);
		printf("%d\n", a % 42);
	}
	return 0;
}