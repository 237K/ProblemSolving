//
//	OS Windows
//	2019.09.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1546 ЦђБе
//

#include <stdio.h>
int arr[1001];
int main(void)
{
	freopen("input1546.txt", "r", stdin);
	int N, n, M, max_score = 0;
	double avg = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
		if (max_score < arr[n]) max_score = arr[n];
	}
	for (n = 0; n < N; ++n)
		avg += (double)arr[n] / (double)max_score * (double)100;
	avg /= N;
	printf("%.2f", avg);
	return 0;
}