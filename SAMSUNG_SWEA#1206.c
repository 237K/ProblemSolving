//
//	OS Windows
//	2019.04.26
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1206] <View> (SW문제해결 기본)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int main(int argc, char** argv)
{
	freopen("s_input1206.txt", "r", stdin);
	int T = 10;
	int N;
	int buildings[1001];
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(buildings, 0, sizeof(buildings));
		int result = 0;
		scanf("%d", &N);
		for (register int n = 0; n < N; ++n)
			scanf("%d", &buildings[n]);
		for (register int i = 2; i < N - 2; ++i)
		{
			int higher = 0;
			for (register int j = 1; j <= 2; ++j)
			{
				if (buildings[i] < buildings[i + j] + 1 || buildings[i] < buildings[i - j] + 1)
				{
					higher = -1;
					break;
				}
				else
				{
					if (higher < buildings[i + j]) higher = buildings[i + j];
					if (higher < buildings[i - j]) higher = buildings[i - j];
				}
			}
			if (higher == -1) continue;
			else
			{
				result += buildings[i] - higher;
				i += 2;
			}
		}
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}