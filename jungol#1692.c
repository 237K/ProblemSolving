//
//	OS Windows
//	2020.04.18
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1692> °ö¼À
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N1, N2, tmp, cur;
	scanf("%d\n%d", &N1, &N2);
	tmp = N2;
	while (tmp)
	{
		cur = tmp % 10 * N1;
		printf("%d\n", cur);
		tmp /= 10;
	}
	printf("%d", N1*N2);
	return 0;
}