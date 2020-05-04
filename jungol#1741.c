//
//	OS Windows
//	2020.04.27
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1741> 독서대회
//
#define _CRT_SECURE_NO_WARNING
int main(void)
{
	int N, K, n, k, S, T, t, R, cnt;
	scanf("%d %d", &N, &K);
	for (k = 0; k < K; ++k)
	{
		scanf("%d %d %d", &S, &T, &R);
		n = N; cnt = 0; t = T;
		while (1)
		{
			n -= S;
			cnt++;
			if (n <= 0) break;
			if (!(--t))
			{
				cnt += R;
				t = T;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}