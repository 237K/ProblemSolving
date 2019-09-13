//
//	OS Windows
//	2019.09.13
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#1945> (D2) 간단한 소인수분해
//

#include <stdio.h>
int arr[5];
int T, N;
void go()
{
	register int cnt = 0, i, rmd;
	while (N)
	{
		rmd = N % 2;
		if (rmd) break;
		cnt++;
		N /= 2;
	}
	arr[0] = cnt;
	cnt = 0;
	while (N)
	{
		rmd = N % 3;
		if (rmd) break;
		cnt++;
		N /= 3;
	}
	arr[1] = cnt;
	cnt = 0;
	while (N)
	{
		rmd = N % 5;
		if (rmd) break;
		cnt++;
		N /= 5;
	}
	arr[2] = cnt;
	cnt = 0;
	while (N)
	{
		rmd = N % 7;
		if (rmd) break;
		cnt++;
		N /= 7;
	}
	arr[3] = cnt;
	cnt = 0;
	while (N)
	{
		rmd = N % 11;
		if (rmd) break;
		cnt++;
		N /= 11;
	}
	arr[4] = cnt;
	for (i = 0; i < 5; ++i) printf("%d ", arr[i]);
	printf("\n");
}
int main(void)
{
	register int tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		printf("#%d ", tc);
		scanf("%d", &N);
		go();
	}
	return 0;
}