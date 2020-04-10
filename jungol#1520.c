//
//	OS Windows
//	2020.04.05
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1520> 계단오르기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STAIR 300
int arr[STAIR], N, ret;
void recur(int cur, int flag, int sum)
{
	if (cur >= N)
	{
		if (cur == N && ret < sum)
			ret = sum;
		return;
	}
	if (flag < 2)
	{
		recur(cur + 1, flag + 1, sum + arr[cur+1]);
		recur(cur + 2, 1, sum + arr[cur+2]);
	}
	else recur(cur + 2, 1, sum + arr[cur+2]);
}
int main(void)
{
	freopen("jinput1520.txt", "r", stdin);
	register int n;
	ret = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
	}
	recur(-1, 0, 0);
	printf("%d", ret);
	return 0;
}