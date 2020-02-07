//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1003> 줄 세우기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 102
int arr[MAX], N, n;
void shift(int idx, int cnt)
{
	register int i, tmp;
	tmp = arr[idx];
	for (i = idx; i >= idx - cnt; --i)
		arr[i] = arr[i - 1];
	arr[idx - cnt] = tmp;
}
void print()
{
	register int i;
	for (i = 0; i < N; ++i)
		printf("%d ", arr[i]);
}
int main(void)
{
	freopen("jinput1003.txt", "r", stdin);
	register int i;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) arr[i - 1] = i;
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &n);
		if (!n) continue;
		shift(i, n);
	}
	print();
	return 0;
}