//
//	OS Windows
//	2019.05.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5431] (D3) 민석이의 과제 체크하기
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int main(void)
{
	freopen("s_input5431.txt", "r", stdin);
	int arr[101];
	int T, N, S, in;
	register int tc, s, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(arr, 0, sizeof(arr));
		scanf("%d %d", &N, &S);
		for (s = 0; s < S; ++s)
		{
			scanf("%d", &in);
			arr[in] = 1;
		}
		printf("#%d ", tc);
		for (i = 1; i <= N; ++i) if (!arr[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}