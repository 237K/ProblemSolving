//
//	OS Windows
//	2019.12.10
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #1731>	추론
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[5];
int N, diff1, diff2, diff3, what;
int main(void)
{
	freopen("input1731.txt", "r", stdin);
	register int i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		if (i < 5) scanf("%d", &arr[i]);
		else scanf("%d", &arr[4]);
	}
	diff1 = arr[1] - arr[0];
	diff2 = arr[2] - arr[1];
	diff3 = arr[3] - arr[2];
	if (diff1 == diff2 && diff2 == diff3)
	{
		printf("%d", arr[4] + diff1);
	}
	else
	{
		diff1 = arr[1] / arr[0];
		printf("%d", arr[4] * diff1);
	}
	return 0;
}