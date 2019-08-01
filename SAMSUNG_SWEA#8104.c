//
//	OS Windows
//	2019.07.24
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8104] (D3) 조 만들기
//

#include <stdio.h>
int T, N, K, arr[21][21];
void cal()
{
	register int i, j, ret;
	arr[1][1] = 1;
	ret = 1;
	for (i = 2; i <= N; ++i)
	{
		if (i % 2) arr[1][i] = arr[1][i - 1] + 1;
		else arr[1][i] = i * K;
		ret += arr[1][i];
	}
	printf("%d ", ret);
	for (i = 2; i <= K; ++i)
	{
		arr[i][1] = i;
		ret = i;
		for (j = 2; j <= N; ++j)
		{
			if (j % 2) arr[i][j] = arr[i-1][j] + 1;
			else arr[i][j] = arr[i-1][j] - 1;
			ret += arr[i][j];
		}
		printf("%d ", ret);
	}
	printf("\n");
}
int main(void)
{
	scanf("%d", &T);
	for (register int tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &K);
		printf("#%d ", tc); cal();
	}
	return 0;
}