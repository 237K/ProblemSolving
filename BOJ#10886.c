//
//	OS Windows
//	2019.08.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10886 not cute / cute
//

#include <stdio.h>
int main(void)
{
	int N, n, a, A = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &a);
		A += a;
	}
	if (A > (N / 2)) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
	return 0;
}