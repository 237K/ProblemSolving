//
//	OS Windows
//	2019.11.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2992	크면서 작은 수
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 7
int N, M;
int arr1[SZ], arr2[SZ];
void trans(int *arr, int n)
{
	register int idx = 0;
	while (n)
	{
		arr[idx++] = n % 10;
		n /= 10;
	}
	if (!M) M = idx;
}
int comp()
{
	register int i, j, flag, ret;
	ret = 1;
	for (i = 0; i < M; ++i)
	{
		flag = 0;
		for (j = 0; j < M; ++j)
		{
			if (arr1[i] == arr2[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}
int main(void)
{
	freopen("input2992.txt", "r", stdin);
	M = 0;
	scanf("%d", &N);
	trans(arr1, N);
	while (N++)
	{
		trans(arr2, N);
		if (comp()) break;
	}
	printf("%d", N);
	return 0;
}