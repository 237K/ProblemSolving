//
//	OS Windows
//	2019.11.28
//
//	[Algorithm Problem Solving]
//
//	[½Ã¹Ä·¹ÀÌ¼Ç] <BOJ #1392>	³ë·¡ ¾Çº¸
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101
int len[MAX];
int N, Q;
int main(void)
{
	freopen("input1392.txt", "r", stdin);
	register int n, q, ret;
	int T;
	scanf("%d %d", &N, &Q);
	for (n = 0; n < N; ++n)
		scanf("%d", &len[n]);
	for (q = 0; q < Q; ++q)
	{
		scanf("%d", &T);
		ret = N;
		for (n = 0; n < N; ++n)
		{
			T -= len[n];
			if (T < 0)
			{
				ret = n + 1;
				break;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}