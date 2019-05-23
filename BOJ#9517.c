//
//	OS Windows
//	2019.05.17
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #9517	아이 러브 크로아티아
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input9517.txt", "r", stdin);
	setbuf(stdout, NULL);
	int K, N, tik = 0, time;
	char A;
	register int n;
	scanf("%d", &K);
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d %c", &time, &A);
		tik += time;
		if (tik >= 210)
			break;
		else
		{
			if (A == 'T')
			{
				if ((++K) == 9) K = 1;
				continue;
			}
		}
	}
	printf("%d", K);
	return 0;
}