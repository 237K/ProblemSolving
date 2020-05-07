//
//	OS Windows
//	2020.04.30
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1810> 백설공주
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 9
#define NAN 7
int arr[SZ], sel[NAN], flag;
void print()
{
	for (register int i = 0; i < NAN; ++i)
		printf("%d\n", arr[sel[i]]);
}
void simul(int cnt, int idx, int sum)
{
	if (flag) return;
	if (cnt == NAN)
	{
		if (sum == 100)
		{
			flag = 1;
			print();
		}
		return;
	}
	for (register int i = idx; i < SZ; ++i)
	{
		sel[cnt] = i;
		simul(cnt + 1, i + 1, sum + arr[sel[cnt]]);
	}
}
int main(void)
{
	freopen("jinput1810.txt", "r", stdin);
	register int i;
	flag = 0;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &arr[i]);
	}
	simul(0, 0, 0);
	return 0;
}