//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[����] <jungol#1416> ������
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
	if (ret) printf("�հ�");
	else printf("���հ�");
	return 0;
}