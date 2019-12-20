//
//	OS Windows
//	2019.11.20
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <BOJ #5624>	좋은 수
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 5001;
static int arr[MAX], check[MAX], sel[3];
static int N, ret;
inline void dfs(int cnt, int idx)
{
	if (check[idx]) return;
	if (cnt == 3)
	{
		register int sum = 0;
		for (register int j = 0; j < cnt; ++j)
		{
			sum += sel[j];
		}
		if (sum == arr[idx])
		{
			if (!check[idx])
			{
				check[idx] = 1;
				ret++;
			}
		}
		return;
	}
	for (register int i = 0; i < idx; ++i)
	{
		sel[cnt] = arr[i];
		dfs(cnt + 1, idx);
	}
}
int main(int argc, char** argv)
{
	freopen("input5624.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i;
	(void)memset(check, 0, sizeof(check));
	ret = 0;
	cin >> N;
	for (i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (i) dfs(0, i);
	}
	cout << ret;
	return 0;
}