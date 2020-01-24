//
//	OS Windows
//	2019.11.26
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1284	Áý ÁÖ¼Ò
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[4];
void cal(int n)
{
	register int i = 0, j, sum;
	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	sum = i + 1;
	for (j = 0; j < i; ++j)
	{
		if (!arr[j]) sum += 4;
		else if (arr[j] == 1) sum += 2;
		else if (arr[j] > 1) sum += 3;
	}
	printf("%d\n", sum);
}
int main(void)
{
	freopen("input1284.txt", "r", stdin);
	int N, ret;
	while (1)
	{
		scanf("%d", &N);
		if (!N) break;
		cal(N);
	}
	return 0;
}