//
//	OS Windows
//	2020.03.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1207> 간단한 눈치게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
#define SZ 50
int arr[SZ], N;
int main(void)
{
	freopen("jinput1207.txt", "r", stdin);
	register int n, x, y, flag, sum, diff, ret = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
		scanf("%d", &arr[n]);
	for (x = 1; x <= MAX; ++x)
	{
		for (y = 1; y <= MAX; ++y)
		{
			if (x == y) continue;
			flag = 0;
			sum = x + y;
			diff = x - y;
			if (diff < 0) diff *= -1;
			for (n = 0; n < N; ++n)
			{
				if (sum == arr[n]) flag++;
				if (diff == arr[n]) flag++;
			}
			if (flag < 2) continue;
			if (ret < x * y) ret = x * y;
		}
	}
	printf("%d", ret);
	return 0;
}