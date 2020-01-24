//
//	OS Windows
//	2019.11.26
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #1259>	팰린드롬수
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 6
int arr[SZ];
int dep(int n)
{
	register int i = 0, j;
	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	for (j = 0; j < i / 2; ++j)
	{
		if (arr[j] != arr[i - 1 - j]) return 0;
	}
	return 1;
}
int main(void)
{
	int N;
	while (1)
	{
		scanf("%d", &N);
		if (!N) break;
		if (dep(N)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}