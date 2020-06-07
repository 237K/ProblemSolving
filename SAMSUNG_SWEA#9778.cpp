//
//	OS Windows
//	2020.06.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#9778] (D3) 카드 게임
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int SZ = 53;
const static int MAX = 21;
const static int DECK = 11;
static int deck[SZ], T, N, in, sum, diff;
inline void init()
{
	register int i;
	for (i = 2; i <= DECK; ++i)
	{
		if (i == 10) deck[i] = 16;
		else deck[i] = 4;
	}
	sum = 0;
}
inline int check()
{
	diff = MAX - sum;
	register int i, stop = 0, go = 0, flag = 0;
	for (i = 2; i <= DECK; ++i)
	{
		if (i <= diff)
			go += deck[i];
		else
			stop += deck[i];
	}
	if (go > stop) flag = 1;
	return flag;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, n;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		init();
		for (n = 0; n < N; ++n)
		{
			cin >> in;
			deck[in]--;
			sum += in;
		}
		cout << "#" << tc << ' ';
		if (sum >= MAX-1) cout<<"STOP\n";
		else
		{
			if (check()) cout<<"GAZUA\n";
			else cout<<"STOP\n";
		}
	}
	return 0;
}