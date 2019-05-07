//
//	OS Windows
//	2019.05.06
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1057	토너먼트
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv)
{
	freopen("input1057.txt", "r", stdin);
	int N, K, I;
	scanf("%d %d %d", &N, &K, &I);
	int cnt = N, result = 0, flag = 0;
	while (1)
	{
		cnt = cnt / 2 + cnt % 2;
		result++;

		if (K % 2) K = K / 2 + 1;
		else K /= 2;

		if (I % 2) I = I / 2 + 1;
		else I /= 2;

		if (K == I)
		{
			flag = 1;
			break;
		}
		if (cnt < 2) break;
	}
	if (!flag) result = -1;
	printf("%d", result);
	return 0;
}