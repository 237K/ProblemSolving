//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3456] (D3) 직사각형 길이 찾기
//

#include <stdio.h>
int main(void)
{
	int T, a, b, c;
	register int tc, ret;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && a == c) ret = a;
		else
		{
			if (a == b && b != c) ret = c;
			else if (a == c && b != c) ret = b;
			else ret = a;
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}