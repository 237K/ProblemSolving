//
//	OS Windows
//	2019.09.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2839 º≥≈¡ πË¥ﬁ
//

#include <stdio.h>
int main(void)
{
	freopen("input2839.txt", "r", stdin);
	int N;
	register int i, j, ret = 2147000000;
	scanf("%d", &N);
	for (i = 0; i <= N / 5; ++i)
	{
		for (j = 0; j <= N / 3; ++j)
		{
			if ((i * 5) + (j * 3) == N)
			{
				if (ret > i + j) ret = i + j;
			}
		}
	}
	if (ret == 2147000000) ret = -1;
	printf("%d", ret);
	return 0;
}