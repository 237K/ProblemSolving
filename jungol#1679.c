//
//	OS Windows
//	2020.04.18
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1679> 완전제곱수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main(void)
{
	freopen("jinput1657.txt", "r", stdin);
	int M, N, i, cur, sum = 0, low = 0;
	scanf("%d\n%d", &M, &N);
	for (i = MAX; i > 0; --i)
	{
		cur = i * i;
		if (cur >= M && cur <= N)
		{
			sum += cur;
			low = cur;
		}
	}
	if (sum) printf("%d\n%d", sum, low);
	else printf("-1");
	return 0;
}