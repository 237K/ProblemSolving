//
//	OS Windows
//	2019.09.21
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2562 ÃÖ´ñ°ª
//

#include <stdio.h>
int main(void)
{
	int n, i, ma = 0, cnt;
	for (i = 1; i <= 9; ++i)
	{
		scanf("%d", &n);
		if (ma < n)
		{
			ma = n;
			cnt = i;
		}
	}
	printf("%d\n%d", ma, cnt);
	return 0;
}