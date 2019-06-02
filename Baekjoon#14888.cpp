//
//	OS Windows
//	2019.05.27
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14888	연산자 끼워넣기
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const static int OP = 4;
const static int SZ = 11;
const static int INF = 2147000000;

static int number[SZ];
static int number_cpy[SZ];
static int op[OP];
static int op_comb[SZ-1];
static int N, MAX, MIN;
inline int cal()
{
	register int i, acc = 0;
	number_cpy[0] = number[0];
	for (i = 0; i < N-1; ++i)
	{
		if (op_comb[i] == 0) acc = number_cpy[i] + number[i + 1];
		else if (op_comb[i] == 1) acc = number_cpy[i] - number[i + 1];
		else if (op_comb[i] == 2) acc = number_cpy[i] * number[i + 1];
		else acc = number_cpy[i] / number[i + 1];
		number_cpy[i + 1] = acc;
	}
	return acc;
}
inline void recur(int cnt)
{
	if (cnt == N - 1)
	{
		int tmp = cal();
		if (MAX < tmp) MAX = tmp;
		if (MIN > tmp) MIN = tmp;
		return;
	}
	for (int i = 0; i < OP; ++i)
	{
		if (op[i])
		{
			op[i]--;
			op_comb[cnt] = i;
			recur(cnt + 1);
			op[i]++;
		}
	}
}
int main(void)
{
	freopen("input14888.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	MAX = -INF; MIN = INF;
	register int n, o;
	cin >> N;
	for (n = 0; n < N; ++n)	cin >> number[n];
	for (o = 0; o < OP; ++o) cin >> op[o];
	recur(0);
	cout << MAX << '\n' << MIN;
	return 0;
}