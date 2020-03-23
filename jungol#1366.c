//
//	OS Windows
//	2020.03.13
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1366> 점수계산
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("jinput1366.txt", "r", stdin);
	int N, n, i, cnt = 0, score = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &i);
		if (i) cnt++;
		else cnt = 0;
		score += cnt;
	}
	printf("%d", score);
	return 0;
}