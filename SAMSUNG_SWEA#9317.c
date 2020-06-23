//
//	OS Windows
//	2020.06.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#9317] (D3) 석찬이의 받아쓰기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100001
char index[SZ], input[SZ];
int main(void)
{
	freopen("sinput9317.txt", "r", stdin);
	int T, tc, N, n, cnt;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		index[0] = input[0] = '/0';
		cnt = 0;
		scanf("%s\n%s", &index, &input);
		for (n = 0; n < N; ++n)
		{
			if (index[n] == input[n])
				cnt++;
		}
		printf("#%d %d\n", tc, cnt);
	}
	return 0;
}