//
//	OS Windows
//	2019.09.29
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #4344 평균은 넘겠지
//

#include <stdio.h>
int T, N;
int arr[1001];
int main(void)
{
	freopen("input4344.txt", "r", stdin);
	register int tc, n, sum, cnt;
	double avg, ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		sum = cnt = 0;
		scanf("%d", &N);
		for (n = 0; n < N; ++n)
		{
			scanf("%d", &arr[n]);
			sum += arr[n];
		}
		avg = (double)(sum / N);
		for (n = 0; n < N; ++n)
		{
			if ((double)arr[n] > avg) cnt++;
		}
		ret = (double)cnt / (double)N * (double)100;
		printf("%.3f%%\n", ret);
	}
	return 0;
}