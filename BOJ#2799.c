//
//	OS Windows
//	2019.11.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2799	블라인드
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 502
char map[SZ][SZ];
int arr[5];
int N, M;
int main(void)
{
	freopen("input2799.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	register int r, c, rr, cnt;
	(void)memset(arr, 0, sizeof(arr));
	for (r = 0; r < N*5+1; ++r) scanf("%s", &map[r]);
	for (r = 1; r < N * 5 + 1; r+=5)
	{
		for (c = 1; c < M * 5 + 1; c += 5)
		{
			cnt = 0;
			for (rr = r; rr < r + 5; ++rr)
			{
				if (map[rr][c] == '*') cnt++;
			}
			arr[cnt]++;
		}
	}
	for (r = 0; r < 5; ++r) printf("%d ", arr[r]);
	return 0;
}