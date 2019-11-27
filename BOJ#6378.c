//
//	OS Windows
//	2019.11.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #6378	디지털 루트
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1001
char in[SZ];
int cal()
{
	register int i, sum = 0;
	for (i = 0; in[i]; ++i) sum += in[i] - '0';
	return sum;
}
int cal2(int n)
{
	register int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int droot()
{
	int cur, ret;
	cur = cal();
	while (1)
	{
		ret = cur;
		if (ret < 10) break;
		cur = cal2(cur);
	}
	return ret;
}
int main(void)
{
	freopen("input6378.txt", "r", stdin);
	while (1)
	{
		scanf("%s", &in);
		if (in[0] == '0') break;
		printf("%d\n", droot());
	}
	return 0;
}