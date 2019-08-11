//
//	OS Windows
//	2019.08.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10539	수빈이와 수열
//

#include <stdio.h>
int arr[101];
int sum[101];
int N;
void sol()
{
	register int i;
	sum[0] = arr[0];
	printf("%d ", sum[0]);
	for (i = 1; i < N; ++i)
	{
		sum[i] = arr[i] * (i + 1);
		printf("%d ", sum[i] - sum[i - 1]);
	}
}
int main(void)
{
	freopen("input10539.txt", "r", stdin);
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; ++i) scanf("%d", &arr[i]);
	sol();
	return 0;
}