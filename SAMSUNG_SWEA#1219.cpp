//
//	OS Windows
//	2019.07.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1219] (D4) ±Ê√£±‚
//

#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

const static int NODE = 100;
static vector<int> graph[NODE];
static bool check[NODE];

inline int init()
{
	for (register int i = 0; i < NODE; ++i) graph[i].clear();
	(void)memset(check, 0, sizeof(check));
}
inline int navi()
{
	stack<int> st;
	st.push(0);
	check[0] = true;
	while (!st.empty())
	{
		int cur = st.top();
		st.pop();
		for (vector<int>::size_type i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];
			if (next == 99) return 1;
			if (!check[next])
			{
				st.push(next);
				check[next] = true;
			}
		}
	}
	return 0;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, start, end;
	register int tc, i;
	for (tc = 1; tc <= 10; ++tc)
	{
		init();
		cin >> T >> N;
		for (i = 0; i < N; ++i)
		{
			cin >> start >> end;
			graph[start].push_back(end);
		}
		cout << "#" << T << ' ' << navi() << '\n';
	}
	return 0;
}