//
//	OS Windows
//	2019.09.11
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2029] (D1) ��� ������ ����ϱ�
//

#include <stdio.h>
int main(void)
{
	int T, a, b, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &a, &b);
		printf("#%d %d %d\n", tc, a / b, a % b);
	}
	return 0;
}