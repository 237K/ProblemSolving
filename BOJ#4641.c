//
//	OS Windows
//	2019.11.13
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #4641	Doubles
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 15
int arr[MAX];
int main(void)
{
	freopen("input4641.txt", "r", stdin);
	register int i, j, k, cur, cnt, tc;
	tc = 1;
	while (1)
	{
		i = 0;
		scanf("%d", &arr[i++]);
		if (arr[0] == -1) break;
		while (1)
		{
			scanf("%d", &arr[i]);
			if (!arr[i]) break;
			i++;
		}
		cnt = 0;
		for (j = 0; j < i; ++j)
		{
			cur = arr[j] * 2;
			for (k = 0; k < i; ++k)
			{
				if (j == k) continue;
				if (arr[k] == cur) cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}