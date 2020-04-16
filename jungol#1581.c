//
//	OS Windows
//	2020.04.14
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1581> 두 배열의 합
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1000
int arr1[SZ], arr2[SZ], cnt1, cnt2, in, T;
int main(void)
{
	freopen("jinput1581.txt", "r", stdin);
	register int i, j, k, l, m, n, flag, cnt, ret = 0;
	scanf("%d", &T);
	scanf("%d", &cnt1);
	for (i = 0; i < cnt1; ++i) scanf("%d", &arr1[i]);
	scanf("%d", &cnt2);
	for (i = 0; i < cnt2; ++i) scanf("%d", &arr2[i]);
	for (i = 0; i < cnt1; ++i)
	{
		flag = 1;
		for (j = 1; j <= cnt1 - i; ++j)
		{
			for (k = 0; k < cnt2; ++k)
			{
				for (l = 1; l <= cnt2 - k; ++l)
				{
					cnt = 0;
					for (m = i; m < i + j; ++m)
					{
						cnt += arr1[m];
					}
					if (cnt >= T)
					{
						flag = 0;
						break;
					}
					for (n = k; n < k + l; ++n)
					{
						cnt += arr2[n];
						if (cnt >= T)
						{
							flag = 0;
							continue;
						}
					}
					if (cnt == T)
					{
						//printf("1번행렬 : %d번부터 %d개\n2번행렬 : %d번부터 %d개\n\n", i, j, k, l);
						ret++;
					}
				}
			}
		}
	}
	printf("%d", ret);
	return 0;
}