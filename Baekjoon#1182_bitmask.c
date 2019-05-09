//
//	OS Windows
//	2019.05.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1182	부분수열의 합
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input1182.txt", "r", stdin);
	int N, S;
	int set[20];
	register int i, mask, flag, temp, ret = 0;
	scanf("%d %d", &N, &S);
	for (i = 0; i < N; ++i)
		scanf("%d", &set[i]);
	for (mask = 1; mask < (1 << N); ++mask)
	{
		temp = 0;
		for (flag = 0; flag < N; ++flag)
		{
			if (mask & (1 << flag))
				temp += set[flag];
		}
		if (temp == S) ret++;
	}
	printf("%d", ret);
	return 0;
}