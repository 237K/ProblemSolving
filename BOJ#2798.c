//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2798 ∫Ì∑¢¿Ë
//

#include <stdio.h>
int arr[101];
int N, M, ret;
void recur(int cnt, int idx, int sum)
{
	if (sum > M) return;
	if (cnt == 3)
	{
		if (sum <= M && ret < sum) ret = sum;
		return;
	}
	for (register int i = idx; i < N; ++i)
	{
		recur(cnt + 1, i + 1, sum + arr[i]);
	}
}
int main(void)
{
	freopen("input2798.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (register int i = 0; i < N; ++i) scanf("%d", &arr[i]);
	ret = 0;
	recur(0, 0, 0);
	printf("%d", ret);
	return 0;
}