//
//	OS Windows
//	2019.08.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1265] (D5) ¥ﬁ∂ı∆Æ2
//
#include <stdio.h>
int arr[100];
int main(void)
{
	freopen("s_input1265.txt", "r", stdin);
	int T, N, P, quo, rmd, tc, i;
	long long int ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &P);
		ret = 1;
		quo = N / P;
		rmd = N % P;
		for (i = 0; i < P; ++i) arr[i] = quo;
		for (i = 0; i < P; ++i)
		{
			if (!rmd) break;
			arr[i]++;
			rmd--;
		}
		for (i = 0; i < P; ++i) ret *= arr[i];
		printf("#%d %lld\n", tc, ret);
	}
	return 0;
}