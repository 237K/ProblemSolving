//
//	OS Windows
//	2019.06.11
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#4796> (D4) 의석이의 우뚝 선 산
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50000
int h[MAX];
int N;
int cnt()
{
	register int ret = 0, i, up = 0, down = 0;
	for (i = 0; i < N - 1; ++i)
	{
		if (h[i] < h[i + 1] && !down) up++;
		else if (h[i] > h[i + 1] && up) down++;

		if (down)
		{
			if (i == N - 2)
			{
				ret += up * down;
				break;
			}
			if (h[i] < h[i + 1])
			{
				ret += up * down;
				up = 1; down = 0;
			}
		}
	}
	return ret;
}
int main(void)
{
	freopen("s_input4796.txt", "r", stdin);
	int T;
	register int tc, n;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		for (n = 0; n < N; ++n) scanf("%d", &h[n]);
		printf("#%d %d\n", tc, cnt());
	}
	return 0;
}