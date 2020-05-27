//
//	OS Windows
//	2020.05.26
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2059> 숫자분류
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int category[3], N;
int main(void)
{
	freopen("jinput2059.txt", "r", stdin);
	register int n, k, flag;
	category[0] = category[2] = 1;
	category[1] = 0;
	scanf("%d", &N);
	for (n = 3; n <= N; ++n)
	{
		flag = 1;
		for (k = 2; k < n; ++k)
		{
			if (!(n % k))
			{
				flag = 0;
				break;
			}
		}
		if (!flag) category[1]++;
		else category[2]++;
	}
	for (n = 0; n < 3; ++n)
		printf("%d ", category[n]);
	return 0;
}