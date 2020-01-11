//
//	OS Windows
//	2020.01.02
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2476>	주사위 게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input2476.txt", "r", stdin);
	int N, n, one, two, three, top, cur, ret = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		top = 0;
		scanf("%d %d %d", &one, &two, &three);
		if (one == two && two == three)
		{
			cur = 10000 + (one * 1000);
		}
		else if (one == two)
		{
			cur = 1000 + (one * 100);
		}
		else if (one == three)
		{
			cur = 1000 + (one * 100);
		}
		else if (two == three)
		{
			cur = 1000 + (two * 100);
		}
		else
		{
			if (one > two) top = one;
			else top = two;
			if (top < three) top = three;
			cur = top * 100;
		}
		if (ret < cur) ret = cur;
	}
	printf("%d", ret);
	return 0;
}