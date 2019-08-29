//
//	OS Windows
//	2019.08.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2490	¿∑≥Ó¿Ã
//

#include <stdio.h>
int main(void)
{
	int i, a, b, c, d, r;
	char ret;
	for (i = 0; i < 3; ++i)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		r = a + b + c + d;
		if (!r) ret = 'D';
		else if (r == 1) ret = 'C';
		else if (r == 2) ret = 'B';
		else if (r == 3) ret = 'A';
		else ret = 'E';
		printf("%c\n", ret);
	}
	return 0;
}