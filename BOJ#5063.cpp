//
//	OS Windows
//	2019.08.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5063	TGN
//

#include <stdio.h>
int main(void)
{
	int N, n, r, e, c, p;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d %d", &r, &e, &c);
		p = e - c;
		if (r < p) printf("advertise\n");
		else if (r == p) printf("does not matter\n");
		else printf("do not advertise\n");
	}
	return 0;
}