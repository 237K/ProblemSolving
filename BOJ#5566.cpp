//
//	OS Windows
//	2019.05.27
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5566	주사위 게임
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int MAX = 1001;

static int board[MAX];
static int order[MAX];
static int N, M;

inline int play()
{
	register int cnt = 1, cur = 1;
	while (1)
	{
		cur += order[cnt];
		cur += board[cur];
		if (cur >= N) break;
		cnt++;
	}
	return cnt;
}
int main(void)
{
	freopen("input5566.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int n, m;
	cin >> N >> M;
	for (n = 1; n <= N; ++n) cin >> board[n];
	for (m = 1; m <= M; ++m) cin >> order[m];
	cout << play();
	return 0;
}