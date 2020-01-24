//
//	OS Windows
//	2019.12.26
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2460>	지능형 기차2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
int main(void)
{
	freopen("input2460.txt", "r", stdin);
	int n, in, out, cur = 0, high = 0;
	for (n = 0; n < MAX; ++n)
	{
		scanf("%d %d", &out, &in);
		cur = cur - out + in;
		if (high < cur) high = cur;
	}
	printf("%d", high);
	return 0;
}