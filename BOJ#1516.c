//
//	OS Windows
//	2019.12.09
//
//	[Algorithm Problem Solving]
//
//	[�ùķ��̼�]	<BOJ #1516>	���� ����
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 501
int arr[SZ];
int N, tm, in;
int main(void)
{
	freopen("input1516.txt", "r", stdin);
	(void)memset(arr, 0, sizeof(arr));
	register int n, t;
	scanf("%d", &N);
	for (n = 1; n <= N; ++n)
	{
		t = 0;
		scanf("%d", &tm);
		t += tm;
		while (1)
		{
			scanf("%d", &in);
			if (in == -1) break;
			t += arr[in];
		}
		arr[n] = t;
		printf("%d\n", t);
	}
	return 0;
}