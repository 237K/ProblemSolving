//
//	OS Windows
//	2019.11.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #8974	희주의 수학시험
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int A, B;
int arr[1001];
void mk()
{
	register int i, j, idx = 1;
	for (i = 1; i < 1001; ++i)
	{
		j = i;
		while (j--)
		{
			arr[idx] = i;
			if (idx == B) break;
			idx++;
		}
		if (idx == B) break;
	}
}
int cal()
{
	register int i, sum = 0;
	for (i = A; i <= B; ++i)
		sum += arr[i];
	return sum;
}
int main(void)
{
	freopen("input8974.txt", "r", stdin);
	scanf("%d %d", &A, &B);
	mk();
	printf("%d", cal());
	return 0;
}