//
//	OS Windows
//	2019.05.03
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1966	프린터 큐
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
inline void leftshift(vector<pii>& v, int start, int end)
{
	pii temp = v[start];
	for (register int i = start; i < end; ++i)
	{
		v[i] = v[i + 1];
	}
	v[end] = temp;
}
inline bool is_there_high_priority(vector<pii> v, int idx)
{
	for (vector<pii>::size_type i = idx+1; i < v.size(); ++i)
	{
		if (v[idx].second < v[i].second)
			return true;
	}
	return false;
}
int main(int argc, char** argv)
{
	freopen("input1966.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case;
	int N, M;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		vector<pii> V;
		int p;
		register int n;
		for (n = 0; n < N; ++n)
		{
			cin >> p;
			V.push_back({ n, p });
		}
		int cnt = 1, ft = 0, rear = N - 1;
		while (1)
		{
			if (is_there_high_priority(V, ft))
				leftshift(V, ft, rear);
			else
			{
				if (V[ft].first == M) break;
				ft++;
				cnt++;
			}
			if (ft > rear) break;
		}
		cout << cnt << '\n';
	}
	return 0;
}