//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1526	가장 큰 금민수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int N;
int arr[7];
int check(int n)
{
	(void)memset(arr, 0, sizeof(arr));
	register int idx = 0, i;
	while (n > 0)
	{
		arr[idx++] = n % 10;
		n /= 10;
	}
	for (i = 0; i < idx; ++i)
	{
		if (arr[i] != 4 && arr[i] != 7)
			return 0;
	}
	return 1;
}
int simul()
{
	for (register int i = N; N > 0; --i)
	{
		if (check(i))
			return i;
	}
	return 4;
}
int main(void)
{
	freopen("input1526.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &N);
	printf("%d", simul());
	return 0;
}