//
//	OS Windows
//	2019.11.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #4673	¼¿ÇÁ ³Ñ¹ö
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000
int arr[5];
int cal(int n)
{
	register int sum;
	sum = n;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int simul()
{
	register int i, n, tmp, flag;
	for (i = 1; i <= MAX; ++i)
	{
		flag = 0;
		for (n = 1; n < i; ++n)
		{
			tmp = cal(n);
			if (i == tmp)
			{
				flag = 1;
				break;
			}
		}
		if (!flag) printf("%d\n", i);
	}
}
int main(void)
{
	simul();
	return 0;
}