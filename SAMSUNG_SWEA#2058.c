//
//	OS Windows
//	2019.08.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2058] (D1) 자릿수 더하기
//

#include <stdio.h>
int main(void)
{
	int N, ret = 0;
	scanf("%d", &N);
	while (N)
	{
		ret += N % 10;
		N /= 10;
	}
	printf("%d\n", ret);
	return 0;
}