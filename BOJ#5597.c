//
//	OS Windows
//	2019.08.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5597	과제 안 내신 분..?
//

#include <stdio.h>
#include <memory.h>
int check[31];
int main(void)
{
	freopen("input5597.txt", "r", stdin);
	(void)memset(check, 0, sizeof(check));
	int i, N;
	for (i = 0; i < 30; ++i)
	{
		scanf("%d", &N);
		check[N] = 1;
	}
	for (i = 1; i <= 30; ++i)
		if (!check[i]) printf("%d\n", i);
	return 0;
}