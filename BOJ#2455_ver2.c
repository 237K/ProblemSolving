//
//	OS Windows
//	2019.11.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2455	지능형 기차
//
//	ver.2
//

#define _CRT_SECURE_NO_WARNINS
#include <stdio.h>
int main(void)
{
	int in, out, cur = 0, ret = 0, i;
	for (i = 0; i < 4; ++i)
	{
		scanf("%d %d", &out, &in);
		cur += in - out;
		if (ret < cur) ret = cur;
	}
	printf("%d", ret);
}