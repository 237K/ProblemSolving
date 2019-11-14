//
//	OS Windows
//	2019.11.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3460	ÀÌÁø¼ö
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void transform(int n)
{
	register int idx = 0, rmd;
	while (n)
	{
		rmd = n % 2;
		if (rmd) printf("%d ", idx);
		idx++;
		n /= 2;
	}
	printf("\n");
}
int main(void)
{
	freopen("input3460.txt", "r", stdin);
	int tc, T, n;
	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc)
	{
		scanf("%d", &n);
		transform(n);
	}
	return 0;
}