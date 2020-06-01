//
//	OS Windows
//	2020.06.01
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2130> 피타고라스 수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a, b, c, N, cnt;
int main(void)
{
	freopen("jinput2130.txt", "r", stdin);
	cnt = 0;
	scanf("%d", &N);
	for (a = 3; a <= N; ++a)
	{
		for (b = a; b <= N; ++b)
		{
			for (c = b; c <= N; ++c)
			{
				if ((a * a) + (b * b) == c * c)
					cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}