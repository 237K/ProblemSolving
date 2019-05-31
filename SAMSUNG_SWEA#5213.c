//
//	OS Windows
//	2019.05.30
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5213] (D4) 진수의 홀수 약수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001
long long arr[MAX], acc[MAX];
int main(void)
{
	freopen("s_input5213.txt", "r", stdin);
	int T, L, R;
	register int tc, i, j;
	for (i = 1; i < MAX; ++i)
	{
		if (i % 2)
		{
			for (j = i; j <= MAX; j += i)
			{
				if(j % 2) arr[j] += i;
				else arr[j] = arr[i];
			}
		}
		acc[i] = arr[i] + acc[i - 1];
	}
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &L, &R);
		printf("#%d %lld\n", tc, acc[R] - acc[L - 1]);
	}
	return 0;
}