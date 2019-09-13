//
//	OS Windows
//	2019.09.12
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2019] (D1) 더블더블
//

#include <stdio.h>
int mul(int n)
{
	register int value = 1;
	while (n--)
	{
		value *= 2;
	}
	return value;
}
int main(void)
{
	int i, N;
	scanf("%d", &N);
	for (i = 0; i <= N; ++i) printf("%d ", mul(i));
	return 0;
}