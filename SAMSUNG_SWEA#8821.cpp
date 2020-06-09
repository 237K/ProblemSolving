//
//	OS Windows
//	2020.06.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8821] (D3) 적고 지우기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const static int SZ = 10;
static int arr[SZ], T;
static string str;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, n, cnt, sz, cur;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(arr, 0, sizeof(arr));
		str.clear();
		cin >> str;
		sz = str.length();
		cnt = 0;
		for (n = 0; n < sz; ++n)
		{
			cur = str[n] - '0';
			if (!arr[cur])
			{
				cnt++;
				arr[cur] = 1;
			}
			else
			{
				cnt--;
				arr[cur] = 0;
			}
		}
		cout << "#" << tc << " " << cnt << '\n';
	}
	return 0;
}