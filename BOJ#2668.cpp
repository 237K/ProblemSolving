//
//	OS Windows
//	2019.06.25
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2668 (DFS) 숫자 고르기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int MAX = 101;
static int arr[MAX], ret_arr[MAX];
static vector<int> comb1, comb2;
static int N, ret;
inline void print(vector<int>& v, int c)
{
	for (register int i = 0; i < c; ++i)
		cout << v[i] << ' ';
	cout << '\n';
}
inline void recur(int cnt, int idx)
{
	if (cnt >= N) return;
	if (idx > N) return;

	if (cnt == 3)
	{
		comb2.clear();
		bool flag = true;
		for (register int i = 0; i < cnt; ++i) comb2.push_back(arr[comb1[i]]);
		sort(comb2.begin(), comb2.end());

		//cout << "comb1 : "; print(comb1, cnt); cout << '\n';
		//cout << "comb2 : "; print(comb2, cnt); cout << "\n\n";

		for (register int c = 0; c < cnt; ++c)
		{
			if (comb1[c] != comb2[c])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (ret < cnt)
			{
				ret = cnt;
				for (register int n = 0; n < cnt; ++n)
					ret_arr[n] = comb1[n];
			}
		}
		else return;
	}
	for (register int i = idx; i <= N; ++i)
	{
		comb1[cnt] = i;
		recur(cnt + 1, i + 1);
	}
}
int main(int argc, char** argv)
{
	freopen("input2668.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	ret = 0; comb1.resize(N, 0); comb2.clear();
	for (register int n = 1; n <= N; ++n) cin >> arr[n];
	recur(0, 1);
	cout << ret << '\n';
	for (register int i = 0; i < ret; ++i)
		cout << ret_arr[i] << '\n';
	return 0;
}