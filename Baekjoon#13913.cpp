//
//	OS Windows
//	2019.04.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #13913	¼û¹Ù²ÀÁú4
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <memory.h>
using namespace std;
const static int MAX = 100000;
typedef pair<int, int> pii;
int main(int argc, char** argv)
{
	freopen("input13913.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	queue<pii> Q;
	stack<int> S;
	int N, K;
	int check[MAX];
	int route[MAX];
	(void)memset(check, 0, sizeof(check));
	(void)memset(route, 0, sizeof(route));
	int result = 0;
	cin >> N >> K;
	Q.push({ N, 0 });
	check[N] = 1;
	while (!Q.empty())
	{
		pii cur = Q.front();
		Q.pop();
		if (cur.first == K)
		{
			result = cur.second;
			S.push(K);
			while (S.top() != N)
			{
				int from = route[K];
				S.push(from);
				K = route[K];
			}
			break;
		}
		if (!(check[cur.first + 1]))
		{
			check[cur.first + 1] = 1;
			Q.push({ cur.first + 1, cur.second + 1 });
			route[cur.first + 1] = cur.first;
		}
		if (!(check[cur.first - 1]))
		{
			check[cur.first - 1] = 1;
			Q.push({ cur.first - 1, cur.second + 1 });
			route[cur.first-1] = cur.first;
		}
		if (!(check[cur.first * 2]))
		{
			check[cur.first * 2] = 1;
			Q.push({ cur.first * 2, cur.second + 1 });
			route[cur.first*2] = cur.first;
		}
	}
	cout << result<<'\n';
	while (!S.empty())
	{
		cout << S.top() << ' ';
		S.pop();
	}
	cout << '\n';
	return 0;
}