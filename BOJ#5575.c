//
//	OS Windows
//	2019.08.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5575	타임 카드
//

#include <stdio.h>
int main(void)
{
	int sh, sm, ss, eh, em, es;
	register int i, h, m, s;
	for (i = 0; i < 3; ++i)
	{
		scanf("%d %d %d %d %d %d", &sh, &sm, &ss, &eh, &em, &es);
		s = es - ss;
		if (s < 0)
		{
			em--;
			s += 60;
		}
		m = em - sm;
		if (m < 0)
		{
			eh--;
			m += 60;
		}
		h = eh - sh;
		printf("%d %d %d\n", h, m, s);
	}
	return 0;
}