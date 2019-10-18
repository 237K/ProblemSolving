//
//	OS Windows
//	2019.10.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1260 DFS¿Í BFS
//
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const static int MAX = 1001;
static vector<int> graph[MAX];
static int check[MAX];
static int N, M, V;
inline void dfs()
{
	(void)memset(check, 0, sizeof(check));
	register int cur, nxt, i, sz, flag;
	stack<int> st;
	while (!st.empty()) { st.pop(); }
	st.push(V);
	cout << V << ' ';
	check[V] = 1;
	while (!st.empty())
	{
		flag = 0;
		cur = st.top();
		sz = graph[cur].size();
		for (i = 0; i < sz; ++i)
		{
			nxt = graph[cur][i];
			if (!check[nxt])
			{
				check[nxt] = 1;
				flag = 1;
				cout << nxt << ' ';
				st.push(nxt);
				break;
			}
		}
		if (!flag) st.pop();
	}
	cout << '\n';
}
inline void bfs()
{
	(void)memset(check, 0, sizeof(check));
	register int cur, nxt, i, sz;
	queue<int> Q;
	while (!Q.empty()) { Q.pop(); }
	Q.push(V);
	check[V] = 1;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		cout << cur << ' ';
		sz = graph[cur].size();
		for (i = 0; i < sz; ++i)
		{
			nxt = graph[cur][i];
			if (!check[nxt])
			{
				check[nxt] = 1;
				Q.push(nxt);
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input1260.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, s, e;
	for (i = 0; i < MAX; ++i) graph[i].clear();
	cin >> N >> M >> V;
	for (i = 0; i < M; ++i)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (i = 0; i < N; ++i) sort(graph[i].begin(), graph[i].end());
	dfs();
	bfs();
	return 0;
}