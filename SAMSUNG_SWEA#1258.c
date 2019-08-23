//
//	OS Windows
//	2019.08.23
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1258] (D4) 행렬찾기
//

#include <stdio.h>
#include <memory.h>
int map[100][100];
int check[100][100];
int ret_row[100];
int ret_col[100];
int T, N, num_arr;
void print()
{
	register int i;
	for (i = 0; i < num_arr; ++i)
		printf("%d %d ", ret_row[i], ret_col[i]);
}
void right_shift(int idx)
{
	register int i;
	for (i = num_arr; i > idx; --i)
	{
		ret_row[i] = ret_row[i - 1];
		ret_col[i] = ret_col[i - 1];
	}

}
void solve()
{
	(void)memset(ret_row, 0, sizeof(ret_row));
	(void)memset(ret_col, 0, sizeof(ret_col));
	(void)memset(check, 0, sizeof(check));
	num_arr = 0;
	register int r, c, nr, nc, cnt_r, tmp_c, cnt_c, i, idx, cur, tmp;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (map[r][c] && !check[r][c])
			{
				cnt_r = 0;
				for (nr = r; nr < N; ++nr)
				{
					if (!map[nr][c]) break;
					cnt_r++;
					tmp_c = 0;
					for (nc = c; nc < N; ++nc)
					{
						if (!map[nr][nc]) break;
						check[nr][nc] = 1;
						tmp_c++;
					}
					cnt_c = tmp_c;
				}

				if (!num_arr)
				{
					ret_row[num_arr] = cnt_r;
					ret_col[num_arr++] = cnt_c;
				}
				else
				{
					idx = -1;
					tmp = cnt_r * cnt_c;
					for (i = 0; i < num_arr; ++i)
					{
						cur = ret_row[i] * ret_col[i];
						if(cur > tmp)
						{
							idx = i;
							break;
						}
						else if (cur == tmp)
						{
							if (ret_row[i] > cnt_r)
							{
								idx = i;
								break;
							}
						}
					}
					if (idx == -1) idx = num_arr;
					else right_shift(idx);
					ret_row[idx] = cnt_r;
					ret_col[idx] = cnt_c;
					num_arr++;
				}
			}
		}
	}
}
int main(void)
{
	freopen("s_input1258.txt", "r", stdin);
	register int tc, r, c;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		for (r = 0; r < N; ++r)
			for (c = 0; c < N; ++c)
				scanf("%d", &map[r][c]);
		solve();
		printf("#%d %d ", tc, num_arr); print(); printf("\n");
	}
	return 0;
}