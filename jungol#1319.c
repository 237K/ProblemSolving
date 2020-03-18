//
//	OS Windows
//	2020.03.16
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <jungol#1319> 과자게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
int arr[SZ], prev[SZ], N;
void go()
{
	register int i, nxt;
	for (i = 0; i < N; ++i)
	{
		nxt = (i + 1) % N;
		prev[nxt] = arr[i] / 2;
	}
	for (i = 0; i < N; ++i)
	{
		arr[i] /= 2;
		arr[i] += prev[i];
		if (arr[i] % 2)
			arr[i]++;
	}
}
int check()
{
	register int i, idx, flag = 1;
	idx = arr[0];
	for (i = 1; i < N; ++i)
	{
		if (arr[i] != idx)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
void simul()
{
	register int cnt = 0;
	while (1)
	{
		if (check()) break;
		cnt++;
		go();
	}
	printf("%d %d", cnt, arr[0]);
}
int main(void)
{
	freopen("jinput1319.txt", "r", stdin);
	scanf("%d", &N);
	for (register int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	simul();
	return 0;
}