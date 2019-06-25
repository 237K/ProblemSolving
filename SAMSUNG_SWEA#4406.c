//
//	OS Windows
//	2019.06.25
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4406] (D3) 모음이 보이지 않는 사람
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
static char input[51];
int main(void)
{
	freopen("s_input4406.txt", "r", stdin);
	int T;
	register int tc, i, n;
	scanf("%d\n", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%s", input);
		printf("#%d ", tc);
		for (i = 0; input[i]; ++i)
		{
			n = input[i] - 'a';
			if (n != 0 && n != 4 && n != 8 && n != 14 && n != 20) printf("%c", input[i]);
		}
		printf("\n");
	}
	return 0;
}