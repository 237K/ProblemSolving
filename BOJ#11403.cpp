//
//	OS Windows
//	2019.07.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #11403	경로 찾기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;
const static int MAX = 100;
static int N;
static bool check[MAX];
static int map[MAX][MAX];
static vector<int> route[MAX];
static int ret[MAX][MAX];
static stack<int> st;
inline int find_route(int start, int end)
{
	while (!st.empty()) { st.pop(); }
	(void)memset(check, false, sizeof(check));
	st.push(start);
	check[start] = true;
	while (!st.empty())
	{
		int cur = st.top();
		st.pop();
		for (vector<int>::size_type i = 0; i < route[cur].size(); ++i)
		{
			int next = route[cur][i];
			if (next == end) return 1;
			if (!check[next])
			{
				check[next] = true;
				st.push(next);
			}
		}
	}
	return 0;
}
inline void sol()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			ret[r][c] = find_route(r, c);
		}
	}
}
inline void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cout << ret[r][c] << ' ';
		}
		cout << '\n';
	}
}
int main(int argc, char** argv)
{
	freopen("input11403.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	register int r, c, idx;
	for(r = 0 ; r < N ; ++r)
	{
		idx = 0;
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c]) route[r].push_back(c);
		}
	}
	sol();
	print();
	return 0;
}