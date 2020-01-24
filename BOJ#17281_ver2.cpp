//
//	OS Windows
//	2019.10.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17281	야구
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 51;
const static int PLAYER = 10;
static int table[MAX][PLAYER];
static int selected[PLAYER], check[PLAYER];
static int base[4];
static int N, ret;
inline int simul()
{
	register int score = 0, ining, out_count, cur_player_idx, cur_player_result, rmd_order = 1, order_idx, i, tmp;
	for (ining = 0; ining < N; ++ining)
	{
		(void)memset(base, 0, sizeof(base));
		out_count = 0;
		order_idx = rmd_order;
		while (out_count < 3)
		{
			cur_player_idx = selected[order_idx];
			cur_player_result = table[ining][cur_player_idx];
			if (!cur_player_result)
			{
				out_count++;
			}
			else
			{
				//	3루부터 1루까지 주자 있으면 진루
				for (i = 3; i > 0; --i)
				{
					if (base[i])
					{
						base[i] = 0;
						tmp = i + cur_player_result;
						if (tmp > 3) score++;
						else
						{
							base[tmp]++;
						}
					}
				}
				//	출루
				if (cur_player_result == 4) score++;
				else base[cur_player_result]++;
			}
			order_idx++;
			if (order_idx > 9) order_idx = 1;
		}
		rmd_order = order_idx;
	}
	return score;
}
inline void recur(int cnt)
{
	if (cnt == 10)
	{
		selected[4] = 1;
		int cur = simul();

		//for (register int p = 1; p < PLAYER; ++p) cout << selected[p] << "  ";
		//cout<<"score: "<<cur<<"\n\n";

		if (ret < cur) ret = cur;
		return;
	}
	if (cnt == 4) recur(cnt + 1);
	else
	{
		for (register int i = 2; i < PLAYER; ++i)
		{
			if (!check[i])
			{
				check[i] = 1;
				selected[cnt] = i;
				recur(cnt + 1);
				check[i] = 0;
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input17281.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int i, j;
	ret = 0;
	(void)memset(check, 0, sizeof(check));
	for (i = 0; i < N; ++i)
	{
		for (j = 1; j < PLAYER; ++j)
		{
			cin >> table[i][j];
		}
	}
	recur(1);
	cout << ret;
	return 0;
}