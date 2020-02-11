//
//	OS Windows
//	2020.02.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1037> 오류교정
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 100
int parity[SZ][SZ], N, parity_row, parity_col, parity_cnt;
int main(void)
{
	freopen("jinput1037.txt", "r", stdin);
	scanf("%d", &N);
	register int r, c, cnt;
	parity_row = parity_col = -1;
	parity_cnt = 0;
	for (r = 0; r < N; ++r)
	{
		cnt = 0;
		for (c = 0; c < N; ++c)
		{
			scanf("%d", &parity[r][c]);
			if (parity[r][c])
				cnt++;
		}
		if (cnt % 2)
		{
			parity_cnt++;
			parity_row = r;
		}
	}
	if (parity_cnt > 1) printf("Corrupt");
	else
	{
		parity_cnt = 0;
		for (c = 0; c < N; ++c)
		{
			cnt = 0;
			for (r = 0; r < N; ++r)
			{
				if (parity[r][c])
					cnt++;
			}
			if (cnt % 2)
			{
				parity_cnt++;
				parity_col = c;
			}
		}
		if (parity_cnt > 1) printf("Corrupt");
		else if (parity_row == -1 && parity_col == -1) printf("OK");
		else printf("Change bit (%d,%d)", parity_row + 1, parity_col + 1);
	}
	return 0;
}