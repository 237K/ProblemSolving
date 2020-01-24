//
//	OS Windows
//	2020.01.02
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2495>	연속구간
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 9
char arr[SZ];
int main(void)
{
	freopen("input2495.txt", "r", stdin);
	int t, N, n, cnt = 1, ret = 1;
	for (t = 0; t < 3; ++t)
	{
		scanf("%s", &arr);
		for (n = 1; n < SZ - 1; ++n)
		{
			if (arr[n] == arr[n - 1]) cnt++;
			else
			{
				if (ret < cnt) ret = cnt;
				cnt = 1;
			}
		}
		if (ret < cnt) ret = cnt;
		printf("%d\n", ret);
	}
	return 0;
}