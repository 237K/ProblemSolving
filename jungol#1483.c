//
//	OS Windows
//	2020.04.04
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1483> 숫자 찾기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 7
int arr[SZ], sel[SZ], check[SZ], len, ret = 1000001;
void sep(int x)
{
	len = 0;
	while (x)
	{
		arr[len++] = x % 10;
		x /= 10;
	}
}
int assemble()
{
	register int a = 0, i;
	for (i = 0; i < len; ++i)
	{
		a *= 10;
		a += arr[sel[i]];
	}
	return a;
}
void recur(int cnt, int x)
{
	if (cnt == len)
	{
		int cur = assemble();
		if (cur > x && ret > cur) ret = cur;
		return;
	}
	for (register int i = 0; i < len; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			sel[cnt] = i;
			recur(cnt + 1, x);
			check[i] = 0;
		}
	}
}
void simul(int x)
{
	(void)memset(check, 0, sizeof(check));
	sep(x);
	recur(0, x);
	printf("%d", ret);
}
int main(void)
{
	freopen("jinput1483.txt", "r", stdin);
	int X;
	scanf("%d", &X);
	simul(X);
	return 0;
}