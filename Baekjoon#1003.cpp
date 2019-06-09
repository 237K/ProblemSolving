//
//	OS Windows
//	2019.06.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1003	피보나치 함수
//
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
const static int MAX = 41;
static pii mem[MAX] = { {1, 0}, {0, 1 }, {1, 1}, };
pii operator+ (const pii& left, const pii& right)
{
	return { left.first + right.first, left.second + right.second };
}

int main(int argc, char** argv)
{
	freopen("input1003.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	register int tc, i;
	for (i = 3; i < MAX; ++i)
	{
		mem[i] = mem[i - 1] + mem[i - 2];
	}
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		cout << mem[N].first << ' ' << mem[N].second << '\n';
	}
	return 0;
}