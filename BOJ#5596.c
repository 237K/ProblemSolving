//
//	OS Windows
//	2019.08.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5596	시험 점수
//

#include <stdio.h>
int main(void)
{
	int i, j, in, S = 0, T = 0;
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			scanf("%d", &in);
			if (!i) S += in;
			else T += in;
		}
	}
	if (S < T) S = T;
	printf("%d", S);
	return 0;
}