//
//	OS Windows
//	2019.08.24
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1259] (D5) 금속막대
//

#include <iostream>
#include <memory.h>
using namespace std;
const static int MAX = 20;
static int male[MAX], female[MAX], ret_idx[MAX];
static int T, N;
inline void solve()
{
	//	제일 앞에 와야하는 나사 찾기(수나사와 매칭되는 암나사가 없는 나사)
	register int i, j, front, cur, flag, cur_female;
	for (i = 0; i < N; ++i)
	{
		cur = male[i];
		flag = 0;
		for (j = 0; j < N; ++j)
		{
			if (i == j) continue;
			if (cur == female[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			front = i;
			break;
		}
	}
	ret_idx[0] = front;
	//	이제 뒤에 올 나사 하나씩 연결
	for (i = 1; i < N; ++i)
	{
		cur_female = female[ret_idx[i - 1]];
		for (j = 0; j < N; ++j)
		{
			if (ret_idx[i - 1] == j) continue;
			if (cur_female == male[j])
			{
				ret_idx[i] = j;
				break;
			}
		}
	}
	//	출력
	for (i = 0; i < N; ++i) cout << male[ret_idx[i]] << ' ' << female[ret_idx[i]] << ' ';
	cout << '\n';
}
int main(int argc, char** argv)
{
	freopen("s_input1259.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, n;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		for (n = 0; n < N; ++n)
		{
			cin >> male[n] >> female[n];
		}
		cout << "#" << tc << ' '; solve();
	}
	return 0;
}