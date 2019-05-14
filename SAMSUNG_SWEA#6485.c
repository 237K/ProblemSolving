//	2019.05.12
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6485] (D3) 삼성시의 버스 노선
//	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int bus_stop[500];
int bus_start[500];
int bus_end[500];
int T, N, P;
void cal()
{
	register int n, p, cnt, cur;
	for (p = 0; p < P; ++p)
	{
		cur = bus_stop[p]; cnt = 0;
		for (n = 0; n < N; ++n)
		{
			if (cur >= bus_start[n] && cur <= bus_end[n]) cnt++;
		}
		printf("%d ", cnt);
	}
}
int main(int argc, char** argv)
{
	freopen("s_input6485.txt", "r", stdin);
	register int test_case, n, p;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		for (n = 0; n < N; ++n)
		{
			scanf("%d %d", &bus_start[n], &bus_end[n]);
		}
		scanf("%d", &P);
		for (p = 0; p < P; ++p)
		{
			scanf("%d", &bus_stop[p]);
		}
		printf("#%d ", test_case);
		cal();
		printf("\n");
	}
	return 0;
}