//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#6190> (D3) 정곤이의 단조 증가하는 수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int T, N;
int arr[1000];
int num[10];
int max;
int check(int n)
{
	(void)memset(num, 0, sizeof(num));
	register int idx, rmd, i, j;
	idx = 0;
	while (n > 0)
	{
		rmd = n % 10;
		n /= 10;
		num[idx++] = rmd;
	}
	for (i = 0; i < idx-1; ++i)
	{
		for (j = i+1; j < idx; ++j)
		{
			if (num[i] < num[j]) return 0;
		}
	}
	return 1;
}
int simul()
{
	register int i, j, mul;
	for(i = 0 ; i < N-1 ; ++i)
	{
		for (j = i + 1; j < N; ++j)
		{
			mul = arr[i] * arr[j];
			if (mul < max) continue;
			else
			{
				if (check(mul)) max = mul;
			}
		}
	}
	return max;
}
int main(void)
{
	freopen("s_input6190.txt", "r", stdin);
	setbuf(stdout, NULL);
	register int test_case, n;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(arr, 0, sizeof(arr));
		max = 0;
		scanf("%d", &N);
		for (n = 0; n < N; ++n)
		{
			scanf("%d ", &arr[n]);
		}
		printf("#%d %d\n", test_case, simul());
	}
	return 0;
}