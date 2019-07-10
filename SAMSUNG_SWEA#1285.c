//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1285] (D2) 아름이의 돌 던지기
//

#include <stdio.h>
int main(void)
{
	int T, N, in;
	register int tc, i, dist, num;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		dist = 100001; num = 1;
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &in);
			if (in < 0) in *= -1;
			if (dist > in)
			{
				dist = in;
				num = 1;
			}
			else if(in == dist)
			{
				num++;
			}
		}
		printf("#%d %d %d\n", tc, dist, num);
	}
	return 0;
}