//
//	OS Windows
//	2019.04.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7193] <승현이의 수학공부> (D3)
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("s_input7193.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T, N;
	register int test_case, X;
	char in;
	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d ", &N);
		X = 0;
		while (1)
		{
			scanf("%c", &in);
			if (in - '0' < 0) break;
			else X += in - '0';
		}
		printf("#%d %d\n", test_case, X % (N-1));
	}
	return 0;
}