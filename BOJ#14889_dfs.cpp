//
//	OS Windows
//	2020.10.10
//
//	[PS][BOJ[#14889] 스타트와 링크
//	DFS로
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int SZ = 22;
static int map[SZ][SZ], N, check[SZ], sum[2], team[2][SZ / 2], ret;
inline void print()
{
	register int i, j;
	for (i = 0; i < 2; ++i)
	{
		cout << "team " << i + 1 << " : ";
		for (j = 0; j < N / 2; ++j)
		{
			cout << team[i][j] << ' ';
		}
		cout << "\n\n";
	}
}
inline int cal_diff()
{
	register int i, j, k, diff;
	sum[0] = sum[1] = 0;
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < N / 2; ++j)
		{
			for (k = 0; k < N / 2; ++k)
			{
				sum[i] += map[team[i][j]][team[i][k]];
			}
		}
	}
	diff = sum[1] - sum[0];
	if (diff < 0) diff *= -1;
	return diff;
}
inline void comb(int cnt, int idx)
{
	if (cnt == N / 2)
	{
		register int j, cnt2 = 0, diff;
		for (j = 1; j <= N; ++j)
			if (!check[j]) team[1][cnt2++] = j;
		diff = cal_diff();
		if (ret > diff) ret = diff;
		return;
	}
	for (register int i = idx; i <= N; ++i)
	{
		check[i] = 1;
		team[0][cnt] = i;
		comb(cnt + 1, i + 1);
		check[i] = 0;
	}
}
int main(int argc, char** argv)
{
	freopen("binput14889.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	cin >> N;
	for (r = 1; r <= N; ++r)
		for (c = 1; c <= N; ++c)
			cin >> map[r][c];
	(void)memset(check, 0, sizeof(check));
	ret = 2147000000;
	comb(0, 1);
	cout << ret;
	return 0;
}