//
//	OS Windows
//	2020.03.28
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1430> 숫자의 개수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 10
int arr[SZ], A, B, C, mul, i, p;
int main(void)
{
	(void)memset(arr, 0, sizeof(arr));
	scanf("%d\n%d\n%d", &A, &B, &C);
	mul = A * B * C;
	while (mul)
	{
		i = mul % 10;
		arr[i]++;
		mul /= 10;
	}
	for (p = 0; p < SZ; ++p)
		printf("%d\n", arr[p]);
	return 0;
}