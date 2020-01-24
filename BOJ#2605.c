//
//	OS Windows
//	2020.01.20
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2605>	줄 세우기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[101], N, ticket;
void shift(int s, int e)
{
	register int tmp, i;
	tmp = arr[e];
	for (i = e; i >= s; --i)
		arr[i] = arr[i - 1];
	arr[s] = tmp;
}
void print()
{
	register int i;
	for (i = 0; i < N; ++i)
		printf("%d ", arr[i]);
}
int main(void)
{
	freopen("input2605.txt", "r", stdin);
	register int i;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		arr[i - 1] = i;
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &ticket);
		if (!ticket) continue;
		shift(i-ticket, i);
	}
	print();
	return 0;
}