//
//	OS Windows
//	2019.06.19
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4789] (D3) 성공적인 공연 기획
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("s_input4789.txt", "r", stdin);
	int T;
	register int tc, i, cur, hire, stand;
	char in[1002];
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		hire = stand = 0;
		scanf("%s", &in);
		stand = in[0] - '0';
		for (i = 1; in[i]; ++i)
		{
			cur = in[i] - '0';
			if (stand < i)
			{
				hire += i - stand;
				stand += i - stand;
			}
			stand += cur;
		}
		printf("#%d %d\n", tc, hire);
	}
	return 0;
}