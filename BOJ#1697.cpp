#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int MAX = 111111;
static int N, K;
static int check[MAX];
inline int simul()
{
	if (N >= K) return N - K;
	(void)memset(check, 0, sizeof(check));
	queue<pii> Q;
	register int cur, cnt;
	Q.push({ N, 0 });
	check[N] = 1;
	while (!Q.empty())
	{
		cur = Q.front().first;
		cnt = Q.front().second;
		Q.pop();
		if (cur == K) break;
		if (!check[cur + 1] && cur + 1 < MAX)
		{
			check[cur + 1] = 1;
			Q.push({ cur + 1, cnt + 1 });
		}
		if (!check[cur - 1] && cur - 1 >= 0)
		{
			check[cur - 1] = 1;
			Q.push({ cur - 1, cnt + 1 });
		}
		if (!check[cur * 2] && cur * 2 < MAX)
		{
			check[cur * 2] = 1;
			Q.push({ cur * 2, cnt + 1 });
		}
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	cout << simul();
	return 0;
}