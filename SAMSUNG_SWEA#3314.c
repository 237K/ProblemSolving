//
//	OS Windows
//	2019.07.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3314] (D3) 보충학습과 평균
//

#include <stdio.h>
#define STU 5
int main(void)
{
	int T, tmp;
	register int tc, i, sum, avg;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		sum = avg = 0;
		for (i = 0; i < STU; ++i)
		{
			scanf("%d", &tmp);
			if (tmp < 40) sum += 40;
			else sum += tmp;
		}
		avg = sum / STU;
		printf("#%d %d\n", tc, avg);
	}
	return 0;
}