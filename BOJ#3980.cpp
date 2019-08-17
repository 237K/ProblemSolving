//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #3980	선발 명단
//

#include <iostream>
#include <memory.h>
using namespace std;

const static int MAX = 11;
static int T, ret;
static int table[MAX][MAX];
static int line[MAX], check[MAX];
inline int cal()
{
	register int i, sum = 0;
	for (i = 0; i < MAX; ++i) sum += table[line[i]][i];
	return sum;
}
inline void comb(int cnt)
{
	if (cnt == MAX)
	{
		int tmp = cal();
		if (ret < tmp) ret = tmp;
		for (register int p = 0; p < MAX; ++p) cout << line[p] << ' ';
		cout << " ret : "<<tmp<<"\n\n";
		return;
	}
	for (register int i = 0; i < MAX; ++i)
	{
		if (!check[i] && table[i][cnt])
		{
			check[i] = 1;
			line[cnt] = i;
			comb(cnt + 1);
			check[i] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input3980.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, i, j;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		for (i = 0; i < MAX; ++i)
		{
			for (j = 0; j < MAX; ++j)
			{
				cin >> table[i][j];
			}
		}
		(void)memset(check, 0, sizeof(check)); ret = 0;
		comb(0);
		cout << ret;
	}
	return 0;
}