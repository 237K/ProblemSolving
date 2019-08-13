//
//	OS Windows
//	2019.08.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10708	크리스마스 파티
//

#include <stdio.h>
#include <memory.h>
int arr[101];
int target[101];
int main(void)
{
	freopen("input10708.txt", "r", stdin);
	(void)memset(arr, 0, sizeof(arr));
	int N, M, A;
	register int i, j, X;
	scanf("%d\n%d", &N, &M);
	for (i = 1; i <= M; ++i) scanf("%d", &target[i]);
	for (i = 1; i <= M; ++i)
	{
		X = 0;
		for (j = 1; j <= N; ++j)
		{
			scanf("%d", &A);
			if (A == target[i]) arr[j]++;
			else X++;
		}
		arr[target[i]] += X;
	}
	for (i = 1; i <= N; ++i) printf("%d\n", arr[i]);
	return 0;
}