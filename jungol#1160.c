//
//	OS Windows
//	2020.02.28
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1160> 재정관리
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 12
int main(void)
{
	freopen("jinput1160.txt", "r", stdin);
	float in, sum = 0.00;
	for (register int i = 0; i < SZ; ++i)
	{
		scanf("%f", &in);
		sum += in;
	}
	printf("%.2f", sum / SZ);
	return 0;
}