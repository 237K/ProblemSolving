//
//	OS Windows
//	2020.05.22
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2068> 숫자의 종류
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1000
int arr[SZ], N, cnt;
void check(int input)
{
	register int i, flag = 1;
	for (i = 0; i <= cnt; ++i)
	{
		if (arr[i] == input)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		arr[cnt++] = input;
	}
}
int main(void)
{
	int in, n;
	cnt = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &in);
		check(in);
	}
	printf("%d", cnt);
	return 0;
}