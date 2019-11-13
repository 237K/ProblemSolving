//
//	OS Windows
//	2019.11.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2845	파티가 끝나고 난 뒤
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int main(void)
{
	int i, L, P, pers, news;
	scanf("%d %d", &L, &P);
	pers = L * P;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &news);
		printf("%d ", news - pers);
	}
	return 0;
}