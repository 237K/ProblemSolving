//
//	OS Windows
//	2019.05.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#6019> (D3) 기차 사이의 파리
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double D, A, B, F;
int main(void)
{
	freopen("s_input6019.txt", "r", stdin);
	int T, tc; scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%lf %lf %lf %lf", &D, &A, &B, &F);
		printf("#%d %.6lf\n", tc, (D / (A + B)) * F);
	}
	return 0;
}