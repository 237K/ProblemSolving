//
//	OS Windows
//	2019.08.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5543	상근날드
//

#include <stdio.h>
int main(void)
{
	int i, A, mh = 2001, md = 2001;
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &A);
		if (i < 3)
		{
			if (mh > A) mh = A;
		}
		else
		{
			if (md > A) md = A;
		}
	}
	printf("%d", mh + md - 50);
	return 0;
}