//
//	OS Windows
//	2020.06.02
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2151> 2배수 찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 15
int arr[SZ], N;
int main(void)
{
	register int i, j, n, cur, cnt = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
		scanf("%d", &arr[n]);
	for (i = 0; i < N; ++i)
	{
		cur = arr[i]*2;
		for (j = 0; j < N; ++j)
		{
			if (i == j) continue;
			if (arr[j] == cur)
				cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}