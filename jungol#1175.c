//
//	OS Windows
//	2020.02.28
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1175> 주사위 던지기2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DICE 6
#define MAX 7
int N, M, arr[MAX];
void print()
{
	for (register int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
void simul(int cnt, int sum)
{
	if (cnt == N)
	{
		if (sum == M)
			print();
		return;
	}
	for (register int i = 1; i <= DICE; ++i)
	{
		arr[cnt] = i;
		simul(cnt + 1, sum + i);
	}
}
int main(void)
{
	freopen("jinput1175.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	simul(0, 0);
	return 0;
}