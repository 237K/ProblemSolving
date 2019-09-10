//
//	OS Windows
//	2019.09.11
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2027] (D1) 대각선 출력하기
//

#include <stdio.h>
int main(void)
{
	register int r, c;
	for (r = 0; r < 5; ++r)
	{
		for (c = 0; c < 5; ++c)
		{
			if (r == c) printf("#");
			else printf("+");
		}
		printf("\n");
	}
	return 0;
}