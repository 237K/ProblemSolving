//
//	OS Windows
//	2019.09.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3052 ³ª¸ÓÁö
//

#include <stdio.h>
#include <memory.h>
#define T 10
int arr[10];
int main(void)
{
	(void)memset(arr, -1, sizeof(arr));
	int A, cnt = 0, tc, i, flag;
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &A);
		A %= 42;
		flag = 1;
		for (i = 0; i < cnt; ++i)
		{
			if (arr[i] == A)
			{
				flag = 0;
				break;
			}
		}
		if (flag) arr[cnt++] = A;
	}
	printf("%d", cnt);
	return 0;
}