//
//	OS Windows
//	2019.11.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10040	≈ı«•
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 1001
int A[MAX], B[MAX], vote[MAX];
int N, M;
int main(void)
{
	freopen("input10040.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int n, m, cur_limit, max_cnt = 0, ret = 0;
	(void)memset(vote, 0, sizeof(vote));
	for (n = 1; n <= N; ++n) scanf("%d", &A[n]);
	for (m = 1; m <= M; ++m) scanf("%d", &B[m]);
	for (m = 1; m <= M; ++m)
	{
		cur_limit = B[m];
		for (n = 1; n <= N; ++n)
		{
			if (cur_limit >= A[n])
			{
				if ((++vote[n]) > max_cnt)
				{
					max_cnt = vote[n];
					ret = n;
				}
				break;
			}
		}
	}
	printf("%d", ret);
	return 0;
}