//
//	OS Windows
//	2020.03.04
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1212> 프랑스 외인부대
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 101
int arr[SZ];
int main(void)
{
	int N, n, gender, age, agree, cnt = 0;
	scanf("%d", &N);
	for (n = 1; n <= N; ++n)
	{
		scanf("%d %d %d", &gender, &age, &agree);
		if (gender == 2)
		{
			arr[cnt++] = n;
			continue;
		}
		if (age < 17 || age > 40)
		{
			arr[cnt++] = n;
			continue;
		}
		if (age <= 18 && !agree)
		{
			arr[cnt++] = n;
		}
	}
	printf("%d\n", cnt);
	for (n = 0; n < cnt; ++n)
		printf("%d ", arr[n]);
	return 0;
}