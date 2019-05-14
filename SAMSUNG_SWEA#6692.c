//
//	OS Windows
//	2019.05.12
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6692] (D3) 다솔이의 월급 상자
//	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int T, N, s;
float p;
int main(void)
{
	freopen("s_input6692.txt", "r", stdin);
	register int test_case, n;
	register float ret;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0.0f;
		scanf("%d", &N);
		for (n = 0; n < N; ++n)
		{
			scanf("%f %d", &p, &s);
			ret += (float)(p * s);
		}
		printf("#%d %f\n", test_case, ret);
	}
	return 0;
}