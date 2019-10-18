//
//	OS Windows
//	2019.10.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2606 바이러스
//
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
static vector<int> *GV;
static int N, V;
static int *check;
inline int simul()
{
	register int i, sz, cnt = 0, cur, nxt;
	for (i = 0; i <= N; ++i) check[i] = 0;
	queue<int> Q;
	check[1] = 1;
	Q.push(1);
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		sz = GV[cur].size();
		for (i = 0; i < sz; ++i)
		{
			nxt = GV[cur][i];
			if (!check[nxt])
			{
				check[nxt] = 1;
				Q.push(nxt);
				cnt++;
			}
		}
	}
	return cnt;
}
int main(int argc, char** argv)
{
	freopen("input2606.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, s, e;
	cin >> N >> V;
	GV = new vector<int>[N + 1];
	check = new int[N + 1];
	for (i = 0; i <= N; ++i) GV[i].clear();
	for (i = 0; i < V; ++i)
	{
		cin >> s >> e;
		GV[s].push_back(e);
		GV[e].push_back(s);
	}
	cout << simul();
	return 0;
}