//
//	OS Windows
//	2019.07.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1940] (D2) °¡¶ù! RCÄ«!
//

#include <stdio.h>
int main(void)
{
	int T, N, command, a;
	register int tc, i, v, dist;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		v = dist = 0;
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &command);
			if(command != 0)
			{
				scanf("%d", &a);
				if (command == 1) v += a;
				else v -= a;
				if (v < 0) v = 0;
			}
			dist += v;
		}
		printf("#%d %d\n", tc, dist);
	}
	return 0;
}