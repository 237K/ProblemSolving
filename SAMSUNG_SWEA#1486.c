//
//	OS Windows
//	2019.05.04
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1486] <장훈이의 높은 선반> (D4)
//

#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize ("O3")
#include <stdio.h>
#define MAX 20
int N, B;
int emp[MAX];
int bitmask();

int main(void)
{
	freopen("s_input1486.txt", "r", stdin);
	int T;
	register int test_case, n;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &B);
		for (n = 0; n < N; ++n)
			scanf("%d", &emp[n]);
		printf("#%d %d\n", test_case, bitmask());
	}
	return 0;
}
int bitmask()
{
	int result = 2147000000;
	for (register int mask = 0; mask < (1 << N); ++mask)
	{
		int temp = 0, gap = 0;
		for (register int flag = 0; flag < N; ++flag)
		{
			if ((mask & (1 << flag)))
				temp += emp[flag];
			if (temp >= B) break;
		}
		if (temp >= B)
		{
			gap = temp - B;
			if (result > gap) result = gap;
		}
	}
	return result;
}