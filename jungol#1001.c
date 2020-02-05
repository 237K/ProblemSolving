//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1001> 강아지와 병아리
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a, b, dog, chick, rmd;
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (!a && !b) break;
		if (a > 1000 || b > 4000) printf("INPUT ERROR!\n");
		else
		{
			dog = (b - (a * 2)) / 2;
			rmd = (b - (a * 2)) % 2;
			if (rmd || a < dog || dog < 0) printf("0\n");
			else
			{
				chick = a - dog;
				printf("%d %d\n", dog, chick);
			}
		}
	}
	return 0;
}