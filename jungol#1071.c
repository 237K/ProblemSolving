//
//	OS Windows
//	2020.02.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1071> 약수와 배수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 40
int arr[SZ], N, M, nsum, msum;
int main(void)
{
	nsum = msum = 0;
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &M);
	for (i = 0; i < N; ++i)
	{
		if (arr[i] < M)
		{
			if (!(M % arr[i]))
				nsum += arr[i];
		}
		else if(arr[i] > M)
		{
			if (!(arr[i] % M))
				msum += arr[i];
		}
		else
		{
			nsum += M;
			msum += M;
		}
	}
	printf("%d\n%d", nsum, msum);
	return 0;
}