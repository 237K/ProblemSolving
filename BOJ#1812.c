//
//	OS Windows
//	2019.12.15
//
//	[Algorithm Problem Solving]
//
//	[Ω√πƒ∑π¿Ãº«]	<BOJ #1812>	ªÁ≈¡
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000
int arr[MAX], sum[MAX];
int N;
int main(void)
{
	freopen("input1812.txt", "r", stdin);
	register int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d", &sum[i]);
	i = 0;
	while (i <= sum[0])
	{
		arr[0] = i;
		for (j = 1; j < N; ++j) arr[j] = sum[j - 1] - arr[j - 1];
		if (arr[0] + arr[N - 1] == sum[N - 1]) break;
		i++;
	}
	for (j = 0; j < N; ++j)
	{
		printf("%d\n", arr[j]);
	}
	return 0;
}