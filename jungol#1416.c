//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1416> 시험결과
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 3
int main(void)
{
	int i, in, sum = 0, avg, ret;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &in);
		if (in < 40)
		{
			ret = 0;
			break;
		}
		sum += in;
	}
	avg = sum / SZ;
	if (avg >= 60) ret = 1;
	else ret = 0;
	if (ret) printf("합격");
	else printf("불합격");
	return 0;
}