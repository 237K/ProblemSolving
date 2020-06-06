//
//	OS Windows
//	2020.06.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#9940] (D3) ¼ø¿­1
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 100001
int arr[SZ], N, T, in;
int main(void)
{
	freopen("sinput9940.txt", "r", stdin);
	scanf("%d", &T);
	register int tc, n, i, flag;
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		flag = 1;
		(void)memset(arr, 0, sizeof(arr));
		for (n = 0; n < N; ++n)
		{
			scanf("%d", &in);
			if (!flag || arr[in])
			{
				flag = 0;
				continue;
			}
			arr[in] = 1;
		}
		printf("#%d ", tc);
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}