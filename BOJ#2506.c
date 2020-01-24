//
//	OS Windows
//	2020.01.02
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2506>	점수계산
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	freopen("input2506.txt", "r", stdin);
	int N, n, prev, i, cnt = 1, sum = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d", &i);
		if (!n)
		{
			prev = i;
			sum += i;
		}
		else
		{
			if (prev && i)
			{
				cnt++;
			}
			else if (!i)
			{
				cnt = 0;
			}
			else if (!prev && i)
			{
				cnt = 1;
			}
			prev = i;
			sum += cnt;
		}
	}
	printf("%d", sum);
	return 0;
}