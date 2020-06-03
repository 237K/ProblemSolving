//
//	OS Windows
//	2020.06.02
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2143> 100만들기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 9
#define SEL 7
int arr[SZ], sel[SEL], ret[SEL], eflag;
void print()
{
	register int i;
	for (i = 0; i < SEL; ++i)
	{
		printf("%d\n", ret[i]);
	}
}
void sort()
{
	register int i, j, tmp;
	for (i = 0; i < SEL; ++i)
	{
		ret[i] = arr[sel[i]];
	}
	for (i = 0; i < SEL - 1; ++i)
	{
		for (j = i + 1; j < SEL; ++j)
		{
			if (ret[i] > ret[j])
			{
				tmp = ret[i];
				ret[i] = ret[j];
				ret[j] = tmp;
			}
		}
	}
}
int check()
{
	register int i, sum = 0, flag = 0;
	for (i = 0; i < SEL; ++i)
		sum += arr[sel[i]];
	if (sum == 100)
		flag = 1;
	return flag;
}
void comb(int cnt, int idx)
{
	if (eflag) return;
	if (cnt == SEL)
	{
		if (check())
		{
			eflag = 1;
			sort();
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
	register int i;
	for (i = 0; i < SZ; ++i)
		scanf("%d", &arr[i]);
	eflag = 0;
	comb(0, 0);
	return 0;
}