//
//	OS Windows
//	2020.01.21
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #3040>	백설 공주와 일곱 난쟁이
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 9
#define MAX 7
int arr[SZ], sel[MAX], flag;
int calsum()
{
	register int i, sum = 0;
	for (i = 0; i < MAX; ++i)
	{
		sum += arr[sel[i]];
	}
	return sum;
}
void print()
{
	register int i;
	for (i = 0; i < MAX; ++i)
	{
		printf("%d\n", arr[sel[i]]);
	}
}
void comb(int cnt, int idx)
{
	if (flag) return;
	if (cnt == MAX)
	{
		int cur = calsum();
		if (cur == 100)
		{
			flag = 1;
			print();
		}
		return;
	}
	for (register int i = idx; i < SZ; ++i)
	{
		sel[cnt] = i;
		comb(cnt + 1, i + 1);
	}
}
int main(void)
{
	freopen("input3040.txt", "r", stdin);
	flag = 0;
	int i;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &arr[i]);
	}
	comb(0, 0);
	return 0;
}