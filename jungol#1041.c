//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1041> 완전제곱수1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, M, i, j, tmp, flag;
int main(void)
{
	freopen("jinput1041.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	flag = 0; tmp = 1;
	for (i = N; i <= M; ++i)
	{
		for (j = tmp; j <= i; ++j)
		{
			if (j * j == i)
			{
				flag = 1;
				tmp = j;
				printf("%d ", i);
				break;
			}
		}
	}
	if (!flag) printf("0");
	return 0;
}