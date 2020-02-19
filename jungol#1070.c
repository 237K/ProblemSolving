//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1070> 숫자 맞추기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 4
int xX[SZ], yY[SZ], flag[SZ], X, Y;
void dep()
{
	register int i = SZ-1;
	while (X)
	{
		xX[i--] = X % 10;
		X /= 10;
	}
	i = SZ - 1;
	while (Y)
	{
		yY[i--] = Y % 10;
		Y /= 10;
	}
}
void cal()
{
	dep();
	register int i, j, A = 0, B = 0;
	for (i = 0; i < SZ; ++i) flag[i] = 0;
	for (i = 0; i < SZ; ++i)
	{
		if (xX[i] == yY[i])
		{
			flag[i] = 1;
			A++;
		}
	}
	for (i = 0; i < SZ; ++i)
	{
		if (flag[i]) continue;
		for (j = 0; j < SZ; ++j)
		{
			if (xX[i] == yY[j])
			{
				B++;
			}
		}
	}
	printf("%dA%dB", A, B);
}
int main(void)
{
	scanf("%d %d", &X, &Y);
	cal();
	return 0;
}