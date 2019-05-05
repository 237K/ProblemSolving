//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7194] <화섭이의 미생물 배양> (D4)
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int s, t, a, b;
int dfs()
{
	register int result = 0;
	if (t < s) return -1;
	if (b == 1)
	{
		if (!((t - s) % a)) return (t - s) / a;
		else return -1;
	}
	while (1)
	{
		if (t < s)
		{
			result = -1;
			break;
		}
		if (t == s)	break;
		if (!(t % b))
		{
			t /= b;
			if (t < s)
			{
				t *= b;
				t -= a;
			}
		}
		else t -= a;
		result++;
	}
	return result;
}
int main(void)
{
	freopen("s_input7194.txt", "r", stdin);
	int T;
	register int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d %d", &s, &t, &a, &b);
		printf("#%d %d\n", test_case, dfs());
	}
	return 0;
}