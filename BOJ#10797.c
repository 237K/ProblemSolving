//
//	OS Windows
//	2019.08.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10797	10∫Œ¡¶
//

#include <stdio.h>
int main(void)
{
	int d, c, i, cnt = 0;
	scanf("%d", &d);
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &c);
		if (d == c) cnt++;
	}
	printf("%d", cnt);
	return 0;
}