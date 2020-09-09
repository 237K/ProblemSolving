//
//	OS Windows
//	2020.09.09
//
//	[Algorithm Problem Solving]
//
//	SWEA [#10570] (D3) Á¦°ö ÆÓ¸°µå·Ò ¼ö
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;
const static int SZ = 1001;
const static int MAX = 4;
static int cnt[SZ], check[SZ], arr[MAX], T, A, B;
inline int Dep(int n)
{
	register int i = 0;
	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	return i;
}
inline int PalCheck(int n)
{
	register int flag = 1, i, cur;
	stack<int> ST;
	while (!ST.empty()) { ST.pop(); }
	for (i = 0; i < n / 2; ++i)
		ST.push(arr[i]);
	for (i = (n / 2) + (n % 2); i < n; ++i)
	{
		cur = ST.top();
		ST.pop();
		if (arr[i] != cur)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
inline void init()
{
	register int i, ii, n;
	(void)memset(cnt, 0, sizeof(cnt));
	(void)memset(check, 0, sizeof(check));
	cnt[1] = check[1] = 1;
	for (i = 2; i < 33; ++i)
	{
		if (check[i]) continue;
		check[i] = 1;
		check[i * i] = 1;
		if (i > 9)
		{
			n = Dep(i);
			if (!PalCheck(n)) continue;
		}
		ii = i * i;
		if (ii >= SZ) continue;
		n = Dep(ii);
		if (!PalCheck(n)) continue;
		cnt[ii] = 1;
	}
}
inline int cal()
{
	register int i, count = 0;
	for (i = A; i <= B; ++i)
	{
		if (!cnt[i]) continue;
		count++;
	}
	return count;
}
int main(int argc, char** argv)
{
	freopen("sinput10570.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	cin >> T;
	register int tc;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> A >> B;
		cout << "#" << tc << ' ' << cal() << '\n';
	}
	return 0;
}