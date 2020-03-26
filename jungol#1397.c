//
//	OS Windows
//	2020.03.18
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1397> 스위치1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 501
int arr[SZ], N, M;
void order(int s, int e)
{
	register int i;
	for (i = s; i <= e; ++i)
	{
		if (arr[i]) arr[i] = 0;
		else arr[i] = 1;
	}
}
void check(int s, int e)
{
	register int i, cnt = 0;
	for (i = s; i <= e; ++i)
	{
		if (arr[i]) cnt++;
	}
	printf("%d\n", cnt);
}
int main(void)
{
	freopen("jinput1397.txt", "r", stdin);
	(void)memset(arr, 0, sizeof(arr));
	int m, o, s, e;
	scanf("%d %d", &N, &M);
	for (m = 0; m < M; ++m)
	{
		scanf("%d %d %d", &o, &s, &e);
		if (!o) order(s, e);
		else check(s, e);
	}
	return 0;
}