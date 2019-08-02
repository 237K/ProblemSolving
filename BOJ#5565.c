//
//	OS Windows
//	2019.08.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5565	¿µ¼öÁõ
//

#include <stdio.h>
int main(void)
{
	int total, a;
	register int i;
	scanf("%d", &total);
	for (i = 0; i < 9; ++i)
	{
		scanf("%d", &a);
		total -= a;
	}
	printf("%d", total);
	return 0;
}