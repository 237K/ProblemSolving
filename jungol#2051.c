//
//	OS Windows
//	2020.05.24
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2051> 숫자 찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int N, S, i, j, sum, ret;
	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; ++i)
	{
		sum = 0;
		for (j = 1; j <= N; ++j)
		{
			if (i == j) continue;
			sum += j;
		}
		if (sum == S)
		{
			ret = i;
			break;
		}
	}
	printf("%d", ret);
	return 0;
}