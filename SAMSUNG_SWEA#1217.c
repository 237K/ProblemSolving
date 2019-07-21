//
//	OS Windows
//	2019.07.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1217] (D3) °Åµì Á¦°ö
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	freopen("s_input1217.txt", "r", stdin);
	int T, N, M, ret;
	for (register int tc = 1; tc <= 10; ++tc)
	{
		scanf("%d\n%d %d", &T, &N, &M);
		ret = (int)pow(N, M);
		printf("#%d %d\n", T, ret);
	}
	return 0;
}