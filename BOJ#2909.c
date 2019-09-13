//
//	OS Windows
//	2019.09.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2909 Äµµð ±¸¸Å
//

#include <stdio.h>
int C, K, tmp, quo, rmd;
int main(void)
{
	freopen("input2909.txt", "r", stdin);
	tmp = 1;
	scanf("%d %d", &C, &K);
	while (K--)
	{
		tmp *= 10;
	}
	rmd = C % tmp;
	quo = (C / tmp) * tmp;
	if (rmd >= 5 * tmp / 10) quo += tmp;
	printf("%d", quo);
	return 0;
}