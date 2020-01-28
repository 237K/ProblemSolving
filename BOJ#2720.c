//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #2720>	¼¼Å¹¼Ò »çÀå µ¿Çõ
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 4
int arr[SZ], change, T;
int main(void)
{
	freopen("input2720.txt", "r", stdin);
	scanf("%d", &T);
	register int tc, i;
	for (tc = 0; tc < T; ++tc)
	{
		scanf("%d", &change);
		change *= 100;
		arr[0] = change / 25 / 100;
		change -= arr[0] * 25 * 100;
		arr[1] = change / 10 / 100;
		change -= arr[1] * 10 * 100;
		arr[2] = change / 5 / 100;
		change -= arr[2] * 5 * 100;
		arr[3] = change / 100;
		for (i = 0; i < SZ; ++i) printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}