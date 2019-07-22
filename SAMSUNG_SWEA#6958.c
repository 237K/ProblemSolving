//
//	OS Windows
//	2019.07.22
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6958] (D3) 동철이의 프로그래밍 대회
//

#include <stdio.h>
#include <memory.h>
int sol[20];
int T, N, M, tmp, top, num;
int main(void)
{
	register int tc, r, c;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(sol, 0, sizeof(sol));
		top = num = 0;
		scanf("%d %d", &N, &M);
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < M; ++c)
			{
				scanf("%d", &tmp);
				sol[r] += tmp;
			}
			if (top < sol[r])
			{
				top = sol[r];
				num = 1;
			}
			else if (top == sol[r])
				num++;
		}
		printf("#%d %d %d\n", tc, num, top);
	}
	return 0;
}