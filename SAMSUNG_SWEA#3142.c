//
//	OS Windows
//	2019.07.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3142] (D3) �����̿� �ź��� ���� ��
//

#include <stdio.h>
int main(void)
{
	int T, N, M;
	register int tc, uni, twin;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &M);
		twin = N - M;
		uni = M - twin;
		printf("#%d %d %d\n", tc, uni, twin);
	}
	return 0;
}