//
//	OS Windows
//	2019.11.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2953	나는 요리사다
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 6
int arr[SZ][4];
int main(void)
{
	register int r, c, sum, max_value = 0, ret_num, ret_sum;
	for (r = 1; r < SZ; ++r)
	{
		sum = 0;
		for (c = 0; c < 4; ++c)
		{
			scanf("%d", &arr[r][c]);
			sum += arr[r][c];
		}
		if (max_value < sum)
		{
			ret_num = r;
			ret_sum = sum;
			max_value = sum;
		}
	}
	printf("%d %d", ret_num, ret_sum);
	return 0;
}