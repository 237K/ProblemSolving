//
//	OS Windows
//	2020.03.24
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1402> 약수 구하기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("jinput1402.txt", "r", stdin);
	int N, K, n, k, ret;
	scanf("%d %d", &N, &K);
	ret = k = 0;
	for (n = 1; n <= N; ++n)
	{
		if (!(N % n))
		{
			if ((++k) == K)
			{
				ret = n;
				break;
			}
		}
	}
	printf("%d", ret);
	return 0;
}