//
//	OS Windows
//	2020.04.17
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1644> 진진
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LIMIT 8
int main(void)
{
	int N, n, first, second, sum, low_day = 0, low_time = 0;
	scanf("%d", &N);
	for (n = 1; n <= N; ++n)
	{
		scanf("%d %d", &first, &second);
		sum = first + second;
		if (sum > LIMIT && low_time < sum)
		{
			low_time = sum;
			low_day = n;
		}
	}
	printf("%d", low_day);
	return 0;
}