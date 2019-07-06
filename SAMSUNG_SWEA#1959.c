//
//	OS Windows
//	2019.07.05
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1959] (D2) 두 개의 숫자열
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 20

int short_arr[SZ], long_arr[SZ];
int T, N, M, long_len, short_len;
int main(void)
{
	freopen("s_input1959.txt", "r", stdin);
	register int tc, i, j, k, sum, max_value;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &M);
		if (N > M)
		{
			for (i = 0; i < N; ++i) scanf("%d", &long_arr[i]);
			for (i = 0; i < M; ++i) scanf("%d", &short_arr[i]);
			long_len = N;
			short_len = M;
		}
		else
		{
			for (i = 0; i < N; ++i) scanf("%d", &short_arr[i]);
			for (i = 0; i < M; ++i) scanf("%d", &long_arr[i]);
			long_len = M;
			short_len = N;
		}
		max_value = -2147000000;
		for (i = 0; i <= long_len - short_len; ++i)
		{
			sum = k = 0;
			for (j = i; j < i + short_len; ++j)
				sum += long_arr[j] * short_arr[k++];
			if (max_value < sum) max_value = sum;
		}
		printf("#%d %d\n", tc, max_value);
	}
	return 0;
}