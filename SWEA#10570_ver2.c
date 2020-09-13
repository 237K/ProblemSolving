//
//	OS Windows
//	2020.09.09
//
//	[Algorithm Problem Solving]
//
//	SWEA [#10570] (D3) Á¦°ö ÆÓ¸°µå·Ò ¼ö ver2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 1001
#define MAX 32
#define ARR_SZ 4
int count[SZ], check[SZ], arr[ARR_SZ], T, A, B;
int Dep(int i)
{
	register int c = 0;
	while (i)
	{
		arr[c++] = i % 10;
		i /= 10;
	}
	return c;
}
int PalCheck(int n)
{
	register int i, j, flag = 1;
	for (i = 0; i < n / 2; ++i)
	{
		for (j = n - 1; j >= (n / 2) + (n % 2); --j)
		{
			if (arr[i] != arr[j])
			{
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}
	return flag;
}
void init()
{
	(void)memset(count, 0, sizeof(count));
	(void)memset(arr, 0, sizeof(arr));
	(void)memset(check, 0, sizeof(check));
	register int i, ii, n;
	count[1] = 1;
	for (i = 2; i < MAX; ++i)
	{
		if (check[i]) continue;
		ii = i * i;
		check[i] = 1;
		check[ii] = 1;
		if (i > 10)
		{
			n = Dep(i);
			if (!PalCheck(n)) continue;
		}
		n = Dep(ii);
		if (!PalCheck(n)) continue;
		count[ii] = 1;
	}
}
int cal()
{
	register int i, cnt = 0;
	for (i = A; i <= B; ++i)
	{
		if (!count[i]) continue;
		cnt++;
	}
	return cnt;
}
int main(void)
{
	register int tc;
	init();
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &A, &B);
		printf("#%d %d\n", tc, cal());
	}
	return 0;
}