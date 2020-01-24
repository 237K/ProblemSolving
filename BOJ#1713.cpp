//
//	OS Windows
//	2019.11.20
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <BOJ #1713>	후보 추천하기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const static int SZ = 20;
static deque<pii> dq;
static vector<int> ret;
int main(int argc, char** argv)
{
	freopen("input1713.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, T, t, in, cnt = 0, i, flag;
	cin >> N >> T;
	for (t = 0; t < T; ++t)
	{
		scanf("%d", &in);
		flag = 0;
		if (cnt > 0)
		{
			for (i = 0; i < cnt; ++i)
			{
				if (dq[i].second == in)
				{
					dq[i].first++;
					flag = 1;
				}
			}
			if (!flag)
			{
				if (cnt < N)
				{
					dq.push_back({ 1, in });
					cnt++;
				}
				else
				{
					sort(dq.begin(), dq.end());
					dq.pop_front();
					dq.push_back({ 1, in });
				}
			}
		}
		else
		{
			dq.push_back({ 1, in });
			cnt++;
		}
	}
	for (i = 0; i < N; ++i) ret.push_back(dq[i].second);
	sort(ret.begin(), ret.end());
	for (i = 0; i < N; ++i) cout << ret[i] << ' ';
	return 0;
}