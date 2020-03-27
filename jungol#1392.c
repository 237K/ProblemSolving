//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1392> È¦¼ö
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, low = 101, sum = 0;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &n);
		if (n % 2)
		{
			sum += n;
			if (low > n) low = n;
		}
	}
	printf("%d\n%d", sum, low);
	return 0;
}